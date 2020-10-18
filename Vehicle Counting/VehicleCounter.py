import cv2
import dlib

cap = cv2.VideoCapture('highway.mp4')

def findCenter(x,y,w,h):
    cx = int((x+w)/2)
    cy = int((y+h)/2)
    return cx,cy

def pointInRect(x,y,w,h,cx,cy):
    x1, y1 = cx,cy
    if (x < x1 and x1 < x+w):
        if (y < y1 and y1 < y+h):
            return True
    else:
        return False
    
def main():
    fgbg =  cv2.bgsegm.createBackgroundSubtractorMOG()
    count=0
    SKIP_FRAMES=10
    trackers=[]
    cars_in=0
    cars_out=0
    Font=cv2.FONT_HERSHEY_COMPLEX_SMALL
    while True:    
        ret,frame = cap.read()
        frame_r =  cv2.resize(frame, (640, 480))
        frame_cropped=frame_r[200:640,0:640]

        fgmask_r = fgbg.apply(frame_cropped)
        fgmask_r= cv2.dilate(fgmask_r,(9,9),2)
        contours,h = cv2.findContours(fgmask_r, cv2.RETR_EXTERNAL , cv2.CHAIN_APPROX_SIMPLE)

        for tid,trackersid in enumerate(trackers):
            trackingQuality = trackersid[0].update(frame_cropped)
            
        if (count % SKIP_FRAMES) == 0:
            for num,cnt in enumerate(contours):
                area = cv2.contourArea(cnt)
                if area in range(600,8000):
                        x,y,w,h = cv2.boundingRect(cnt)
                        rect = dlib.rectangle(x,y,x+w,y+h)
                        fx,fy=findCenter(x,y,w,h)
                        matchedTid = None

                        for trackersid in trackers:
                            pos = trackersid[0].get_position()
                            startX = int(pos.left())
                            startY = int(pos.top())
                            endX = int(pos.right())
                            endY = int(pos.bottom())
                            tx,ty=findCenter(startX,startY,endX,endY)
                            t_location_chk = pointInRect(x,y,w,h,tx,ty)
                            if t_location_chk:
                                matchedTid = trackersid
                            
                        if matchedTid is None:
                            tracker = dlib.correlation_tracker()
                            tracker.start_track(frame_cropped, rect)
                            trackers.append([tracker,frame_cropped])

        for num,trackersid in enumerate(trackers):
                pos = trackersid[0].get_position()
                startX = int(pos.left())
                startY = int(pos.top())
                endX = int(pos.right())
                endY = int(pos.bottom())
                offset=5
                cv2.rectangle(frame_cropped, (startX-offset, startY-offset),
                              (endX+offset, endY+offset),(0, 255, 250), 2)
                
                if endY>=280:
                    cars_in+=1
                    trackers.pop(num)
                if startY<0:
                    cars_out+=1
                    trackers.pop(num)
                    
        count+=1
        cv2.putText(frame_r,f"IN:{cars_in}",
                    (20,40),Font,1,(255,0,0),1)
        cv2.putText(frame_r,f"OUT:{cars_out}",
                    (550,40),Font,1,(255,0,0),1)

        cv2.namedWindow("frame")
        cv2.moveWindow("frame",0,0)
        cv2.imshow('frame', frame_r)

        if cv2.waitKey(30) & 0xFF == ord('q'):
            break
    cap.release()
    cv2.destroyAllWindows()


if __name__=="__main__":
    main()
            
                    
                       
            
