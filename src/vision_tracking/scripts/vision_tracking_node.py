#! /usr/bin/env python
import rospy
from vision_tracking.msg import Position
from collections import deque
from pi_video_stream import PiVideoStream
import numpy as np
import cv2
import time

def vision_tracking_node():
    pub = rospy.Publisher('vision_position', Position)
    rospy.init_node('vision_tracking_node', anonymous=True)
    rate = rospy.Rate(10) #  10 Hz

    # Inserting data into messages.
    msg = Position()
    msg.position_x = 500
    msg.position_y = 500

    # Defining boundaries to track the ball.
    lower_boundary = (26, 86, 6)
    upper_boudnary = (71, 255, 255)

    # For the visual line.
    pts = deque(maxlen=60)

    # Start webcam.
    vs = PiVideoStream()
    vs.start()
    time.sleep(1.0)

    while not rospy.is_shutdown():
        # Get current frame.
        frame = vs.read()
        frame = frame[1]

        if frame is None:
            break

        # TODO: Change imutils.
        frame = imutils.resize(frame, width = 600)


        blurred = cv2.GaussianBlur(frame, (11, 11), 0);
        hsv = cv2.cvtColor(blurred, cv2.COLOR_BGR2HSV)
        mask = cv2.inRange(hsv, lower_boundary, higher_boundary)
        mask = cv2.erode(mask, None, iterations = 2)
        mask = cv2.dilate(mask, None, iterations = 2)
        cnts = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        # TODO: Change imutils
        cnts = imutils.grab_contours(cnts)

        center = None

        if len(cnts) > 0:
            c = max(cnts, key = cv2.contourArea)
            ((x, y), radius) = cv2.minEnclosingCircle(c)
            M = cv2.moments(c)
            center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))

            if radius > 10:
                cv2.circle(frame, (int(x), int(y)), int(radius), (0, 255, 255), 2)
                cv2.circle(frame, center, 5, (0, 255, 255), -1)

        pts.appendleft(center)

        for i in range(1, len(pts)):
            if pts[i - 1] is None or pts[i] is None:
                continue

            thickness = int(np.sqrt(args["buffer"] / float(i + 1)) * 2.5)
            cv2.line(frame, pts[i - 1], pts[i], (0,0,255), thickness)

        cv2.imshow("Frame", frame)
        key = cv2/waitKey(1) & 0xFF
        if key == ord("q"):
            break

        # Insert shit here for the loop.
        rospy.loginfo(msg)
        pub.publish(msg)
        rate.sleep()


    if not args.get("video", False):
        vs.stop()
    else:
        vs.release()

    cv2.destroyAllWindows()

if __name__ == '__main__':
    try:
        vision_tracking_node()
    except rospy.ROSInterruptException: pass
