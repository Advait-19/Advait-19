import cv2
import mediapipe as mp
import numpy as np

SMOOTHING_FACTOR = 5

mp_drawing = mp.solutions.drawing_utils
mp_drawing_styles = mp.solutions.drawing_styles
mp_hands = mp.solutions.hands


def track_hand_position(hand_data):
    """Continuously updates hand position and fist status in hand_data."""
    cap = cv2.VideoCapture(0)
    sw = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    sh = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
    hands = mp_hands.Hands(min_detection_confidence=0.5, min_tracking_confidence=0.5)

    while hand_data['running']:
        success, image = cap.read()
        if not success:
            continue

        image = cv2.cvtColor(cv2.flip(image, 1), cv2.COLOR_BGR2RGB)
        results = hands.process(image)
        image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)

        hand_position = None
        is_fist = False

        if results.multi_hand_landmarks:
            for hand_landmarks in results.multi_hand_landmarks:
                x = int(hand_landmarks.landmark[9].x * 1080)  # Scale to Pygame width
                y = int(hand_landmarks.landmark[9].y * 600)   # Scale to Pygame height
                x1 = int(hand_landmarks.landmark[12].x * 1080)
                y1 = int(hand_landmarks.landmark[12].y * 600)

                is_fist = y1 > y  # Detect if fist is closed
                hand_position = (x, y)

                mp_drawing.draw_landmarks(image, hand_landmarks, mp_hands.HAND_CONNECTIONS, mp_drawing_styles.get_default_hand_landmarks_style(),
                                          mp_drawing_styles.get_default_hand_connections_style())

        # Apply smoothing
        if hand_position:
            hand_data['positions'].append(hand_position)
            if len(hand_data['positions']) > SMOOTHING_FACTOR:
                hand_data['positions'].pop(0)

            avg_x = int(np.mean([pos[0] for pos in hand_data['positions']]))
            avg_y = int(np.mean([pos[1] for pos in hand_data['positions']]))

            # Keep racket inside screen bounds
            avg_x = max(0, min(avg_x, 1080 - 80))  # Racket width = 80
            avg_y = max(0, min(avg_y, 600 - 80))   # Racket height = 80

            hand_data['position'] = (avg_x, avg_y)
            hand_data['is_fist'] = is_fist

        # Display camera feed
        resized_image = cv2.resize(image, (sw, sh))
        cv2.imshow('Hand Tracking', resized_image)

        if cv2.waitKey(1) & 0xFF == 27:
            hand_data['running'] = False
            break

    cap.release()
    cv2.destroyAllWindows()

'''
import cv2
import mediapipe as mp
import numpy as np
SMOOTHING_FACTOR = 5

mp_drawing = mp.solutions.drawing_utils
mp_drawing_styles = mp.solutions.drawing_styles
mp_hands = mp.solutions.hands
hand_data = {'position': None, 'is_fist': False, 'running': True, 'positions': []}

def get_hand_position():
    cap = cv2.VideoCapture(0)
    sw = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    sh = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
    hands = mp_hands.Hands(min_detection_confidence=0.5, min_tracking_confidence=0.5)
        
    while cap.isOpened():
        success, image = cap.read()
        if not success:
            print("Ignoring empty camera frame.")
            continue

        # Flip the image horizontally and convert BGR to RGB
        image = cv2.cvtColor(cv2.flip(image, 1), cv2.COLOR_BGR2RGB)
        results = hands.process(image)
        image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)

        hand_position = None
        is_fist = False
        
        if results.multi_hand_landmarks:
            for hand_landmarks in results.multi_hand_landmarks:
                x, y= int(hand_landmarks.landmark[9].x*1080), int(hand_landmarks.landmark[9].y*600)
                x1, y1= int(hand_landmarks.landmark[12].x*1080), int(hand_landmarks.landmark[12].y*600)
                is_fist = y1 > y  # If middle finger tip is below MCP, hand is closed
                hand_position = (x,y)

                #cv2.circle(image, (int(x), int(y)), 10, (0,255,0), -1)
                #cv2.circle(image, (int(x1), int(y1)), 10, (0,0,255), -1)

                mp_drawing.draw_landmarks(image, hand_landmarks, mp_hands.HAND_CONNECTIONS, mp_drawing_styles.get_default_hand_landmarks_style(),mp_drawing_styles.get_default_hand_connections_style())
        
        if hand_position:
            hand_data['positions'].append(hand_position)
            if len(hand_data['positions']) > SMOOTHING_FACTOR:
                hand_data['positions'].pop(0)
            avg_x = int(np.mean([pos[0] for pos in hand_data['positions']]))
            avg_y = int(np.mean([pos[1] for pos in hand_data['positions']]))

            # Prevent racket from going out of bounds
            avg_x = max(0, min(avg_x, 1080 - 80))  # 80 is racket width
            avg_y = max(0, min(avg_y, 600 - 80))   # 80 is racket height
            
            hand_data['position'] = (avg_x, avg_y)
            hand_data['is_fist'] = is_fist          
        
        resized_image= cv2.resize(image, (sw, sh))
        cv2.imshow('MediaPipe Hands', resized_image)

        if cv2.waitKey(1) & 0xFF == 27:  # Press 'ESC' to exit
            break
            
    cap.release()
    cv2.destroyAllWindows()
'''