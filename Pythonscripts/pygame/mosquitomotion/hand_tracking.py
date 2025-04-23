import cv2
import mediapipe as mp
mp_drawing = mp.solutions.drawing_utils
mp_drawing_styles = mp.solutions.drawing_styles
mp_hands = mp.solutions.hands

'''
class HandTracker:
    def __init__(self):
        self.mp_hands = mp.solutions.hands
        self.mp_drawing = mp.solutions.drawing_utils
        self.hands = self.mp_hands.Hands(
            min_detection_confidence=0.5,
            min_tracking_confidence=0.5
        )
        self.cap = cv2.VideoCapture(0)

    def get_hand_position(self):
        """Returns hand position and fist status."""
        success, image = self.cap.read()
        if not success:
            return None, False  # No hand detected

        image = cv2.cvtColor(cv2.flip(image, 1), cv2.COLOR_BGR2RGB)
        image.flags.writeable = False
        results = self.hands.process(image)

        if results.multi_hand_landmarks:
            for hand_landmarks in results.multi_hand_landmarks:
                # Extract x, y of index finger tip (landmark 8)
                index_tip = hand_landmarks.landmark[self.mp_hands.HandLandmark.INDEX_FINGER_TIP]
                x, y = int(index_tip.x * 1080), int(index_tip.y * 600)

                # Detect if hand is closed (using thumb tip and index tip distance)
                thumb_tip = hand_landmarks.landmark[self.mp_hands.HandLandmark.THUMB_TIP]
                distance = abs(index_tip.x - thumb_tip.x)

                is_fist = distance < 0.05  # Small distance means a fist is detected

                return (x, y), is_fist
        
        return None, False  # No hand detected

'''# For webcam input:
cap = cv2.VideoCapture(0)

with mp_hands.Hands(
    min_detection_confidence=0.5,
    min_tracking_confidence=0.5) as hands:
  while cap.isOpened():
    success, image = cap.read()
    if not success:
      print("Ignoring empty camera frame.")
      # If loading a video, use 'break' instead of 'continue'.
      continue

    # Flip the image horizontally for a later selfie-view display, and convert
    # the BGR image to RGB.
    image = cv2.cvtColor(cv2.flip(image, 1), cv2.COLOR_BGR2RGB)
    # To improve performance, optionally mark the image as not writeable to
    # pass by reference.
    image.flags.writeable = False
    results = hands.process(image)

    # Draw the hand annotations on the image.
    image.flags.writeable = True
    image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)
    if results.multi_hand_landmarks:
      for hand_landmarks in results.multi_hand_landmarks:
        mp_drawing.draw_landmarks(
            image,
            hand_landmarks,
            mp_hands.HAND_CONNECTIONS,
            mp_drawing_styles.get_default_hand_landmarks_style(),
            mp_drawing_styles.get_default_hand_connections_style())
    cv2.imshow('MediaPipe Hands', image)
    if cv2.waitKey(5) & 0xFF == 27:
      break
cap.release()
