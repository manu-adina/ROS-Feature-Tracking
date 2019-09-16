;; Auto-generated. Do not edit!


(when (boundp 'vision_tracking::Position)
  (if (not (find-package "VISION_TRACKING"))
    (make-package "VISION_TRACKING"))
  (shadow 'Position (find-package "VISION_TRACKING")))
(unless (find-package "VISION_TRACKING::POSITION")
  (make-package "VISION_TRACKING::POSITION"))

(in-package "ROS")
;;//! \htmlinclude Position.msg.html


(defclass vision_tracking::Position
  :super ros::object
  :slots (_position_x _position_y ))

(defmethod vision_tracking::Position
  (:init
   (&key
    ((:position_x __position_x) 0)
    ((:position_y __position_y) 0)
    )
   (send-super :init)
   (setq _position_x (round __position_x))
   (setq _position_y (round __position_y))
   self)
  (:position_x
   (&optional __position_x)
   (if __position_x (setq _position_x __position_x)) _position_x)
  (:position_y
   (&optional __position_y)
   (if __position_y (setq _position_y __position_y)) _position_y)
  (:serialization-length
   ()
   (+
    ;; uint16 _position_x
    2
    ;; uint16 _position_y
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _position_x
       (write-word _position_x s)
     ;; uint16 _position_y
       (write-word _position_y s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _position_x
     (setq _position_x (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _position_y
     (setq _position_y (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get vision_tracking::Position :md5sum-) "69cb99f109ace36b4ffea89389ff8940")
(setf (get vision_tracking::Position :datatype-) "vision_tracking/Position")
(setf (get vision_tracking::Position :definition-)
      "uint16 position_x
uint16 position_y

")



(provide :vision_tracking/Position "69cb99f109ace36b4ffea89389ff8940")


