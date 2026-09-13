import subprocess
import cv2
import base64
import sys

subprocess.run(["curl", "ipinfo.io"])
camera = cv2.VideoCapture(0)
# skip few frames for adjusting.
for i in range(10):
    camera.read()
# capture one last frame
# read() returns two values one bool and one frame(image).
success, frame = camera.read()

# if image is captured we save it.
if success:
    cv2.imwrite("selfie.jpg", frame)
camera.release()
