# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

import cv2
import numpy as np
import time

def main():
   cap= cv2.VideoCapture(0);
   time.sleep(3)
   for i in range(60):
       ret, background = cap.read()

   while(1):
       ret, img = cap.read()
       hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

       lower_red = np.array([0, 155, 84])
       upper_red = np.array([20, 255, 255])

       mask1 = cv2.inRange(hsv, lower_red, upper_red)

       lower_red2 = np.array([161, 155, 84])
       upper_red2 = np.array([179, 255, 255])

       mask2 = cv2.inRange(hsv, lower_red2, upper_red2)

       mask_r = mask1 + mask2
       mask_r = cv2.morphologyEx(mask_r, cv2.MORPH_OPEN, np.ones((3, 3), np.uint8))
       mask_r = cv2.morphologyEx(mask_r, cv2.MORPH_DILATE, np.ones((3, 3), np.uint8))

       mask2 = cv2.bitwise_not(mask_r)

       vgp = cv2.bitwise_and(img, img, mask=mask2)
       vgp2 = cv2.bitwise_and(background, background, mask=mask_r)
       final = cv2.addWeighted(vgp, 1, vgp2, 1, 0)
       frame_width = int(cap.get(3))
       frame_height = int(cap.get(4))

       size = (frame_width, frame_height)
       cv2.VideoWriter('Pixel_virendrapilaniya.mp4.',cv2.VideoWriter_fourcc(*'MJPG'), 10, size)

       cv2.imshow('frame',final)

       if cv2.waitKey(1) & 0xff == ord('q'):
           break

   cap.release()
   cv2.destroyAllWindows()
if __name__ == '__main__':
   main()

