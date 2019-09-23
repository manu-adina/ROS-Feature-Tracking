#! /usr/bin/env python
import rospy
from vision_tracking.msg import Position
from collections import deque
from pi_video_stream import PiVideoStream
import numpy as np
import cv2
import time

def vision_tracking_node():
    pub = rospy.Publisher('vision_position', Position, queue_size=1)
    rospy.init_node('vision_tracking_node', anonymous=True)

    # Getting parameters from the config file
    resolution_x = rospy.get_param('/vision_tracking_node/resolution_x')
    resolution_y = rospy.get_param('/vision_tracking_node/resolution_y')
    frame_rate = rospy.get_param('/vision_tracking_node/frame_rate')
    cam_saturation = rospy.get_param('/vision_tracking_node/saturation')
    cam_brightness = rospy.get_param('/vision_tracking_node/brightness')

    rate = rospy.Rate(frame_rate)

    # Defining boundaries to track the ball.
    lower_boundary = (29, 86, 6)
    upper_boundary = (64, 255, 255)

    # For the visual line.
    pts = deque(maxlen=30)

    # Start webcam.
    vs = PiVideoStream(resolution=(resolution_x,resolution_y), framerate=frame_rate, saturation=cam_saturation, brightness=cam_brightness)
    vs.start()
    time.sleep(2)

    while not rospy.is_shutdown():
        msg = Position()

        # Get current frame.
        frame = vs.read()

        if frame is None:
            break

        blurred = cv2.GaussianBlur(frame, (11, 11), 0)
        hsv = cv2.cvtColor(blurred, cv2.COLOR_BGR2HSV)
        mask = cv2.inRange(hsv, lower_boundary, upper_boundary)
        mask = cv2.erode(mask, None, iterations = 2)
        mask = cv2.dilate(mask, None, iterations = 2)
        cnts = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        cnts = cnts[1]

        center = None

        if len(cnts) > 0:
            c = max(cnts, key = cv2.contourArea)
            ((x, y), radius) = cv2.minEnclosingCircle(c)

            msg.detected = True
            msg.position_x = x
            msg.position_y = y

            M = cv2.moments(c)
            center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))

            if radius > 10:
                cv2.circle(frame, (int(x), int(y)), int(radius), (0, 255, 255), 2)
                cv2.circle(frame, center, 5, (0, 255, 255), -1)

        else:
            msg.detected = False

        pts.appendleft(center)

        for i in range(1, len(pts)):
            if pts[i - 1] is None or pts[i] is None:
                continue

            thickness = int(np.sqrt(64 / float(i + 1)) * 2.5)
            cv2.line(frame, pts[i - 1], pts[i], (0,0,255), thickness)

        cv2.imshow("Frame", frame)
        key = cv2.waitKey(1) & 0xFF
        if key == ord("q"):
            break

        # rospy.loginfo(msg)
        pub.publish(msg)
        rate.sleep()


    vs.stop()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    try:
        vision_tracking_node()
    except rospy.ROSInterruptException: pass
