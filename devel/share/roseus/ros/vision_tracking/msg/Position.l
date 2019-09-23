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
  :slots (_detected _position_x _position_y ))

(defmethod vision_tracking::Position
  (:init
   (&key
    ((:detected __detected) nil)
    ((:position_x __position_x) 0)
    ((:position_y __position_y) 0)
    )
   (send-super :init)
   (setq _detected __detected)
   (setq _position_x (round __position_x))
   (setq _position_y (round __position_y))
   self)
  (:detected
   (&optional __detected)
   (if __detected (setq _detected __detected)) _detected)
  (:position_x
   (&optional __position_x)
   (if __position_x (setq _position_x __position_x)) _position_x)
  (:position_y
   (&optional __position_y)
   (if __position_y (setq _position_y __position_y)) _position_y)
  (:serialization-length
   ()
   (+
    ;; bool _detected
    1
    ;; uint16 _position_x
    2
    ;; uint16 _position_y
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _detected
       (if _detected (write-byte -1 s) (write-byte 0 s))
     ;; uint16 _position_x
       (write-word _position_x s)
     ;; uint16 _position_y
       (write-word _position_y s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _detected
     (setq _detected (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; uint16 _position_x
     (setq _position_x (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _position_y
     (setq _position_y (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get vision_tracking::Position :md5sum-) "08f7510425c59ccb0f8a2361634fcb13")
(setf (get vision_tracking::Position :datatype-) "vision_tracking/Position")
(setf (get vision_tracking::Position :definition-)
      "bool detected
uint16 position_x
uint16 position_y

")



(provide :vision_tracking/Position "08f7510425c59ccb0f8a2361634fcb13")


