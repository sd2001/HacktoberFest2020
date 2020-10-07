from tkinter import *
from tkinter import messagebox
root=Tk()
root.title("TIC TAC TOE!")
press=True
flag=0
s1="0"
s2="0"
#main game logic
def check(button):
    global press
    global flag
    global s1
    global s2
    
    #alternate player turn's logic
    if button["text"]=="" and press==True:
        button["text"]="X"
        press=False
        flag+=1
    elif button["text"]=="" and press==False:
        button["text"]="O"
        press=True
        flag+=1
    
    # X winning logic
    if (button1["text"]=="X" and button2["text"]=="X" and button3["text"]=="X" or
        button1["text"]=="X" and button4["text"]=="X" and button7["text"]=="X" or
        button2["text"]=="X" and button5["text"]=="X" and button8["text"]=="X" or
        button3["text"]=="X" and button6["text"]=="X" and button9["text"]=="X" or
        button7["text"]=="X" and button8["text"]=="X" and button9["text"]=="X" or
        button4["text"]=="X" and button5["text"]=="X" and button6["text"]=="X" or
        button1["text"]=="X" and button5["text"]=="X" and button9["text"]=="X" or
        button7["text"]=="X" and button5["text"]=="X" and button3["text"]=="X"):
        messagebox.showinfo("GAME OVER","X Is Winner!")
        flag=0
        press=True
        s1=int(s1)
        s1=(s1+1)
        s1=str(s1)
        var0.set(s1)
        reset()
        
    # O winning logic
    elif (button1["text"]=="O" and button2["text"]=="O" and button3["text"]=="O" or
        button1["text"]=="O" and button4["text"]=="O" and button7["text"]=="O" or
        button2["text"]=="O" and button5["text"]=="O" and button8["text"]=="O" or
        button3["text"]=="O" and button6["text"]=="O" and button9["text"]=="O" or
        button7["text"]=="O" and button8["text"]=="O" and button9["text"]=="O" or
        button4["text"]=="O" and button5["text"]=="O" and button6["text"]=="O" or
        button1["text"]=="O" and button5["text"]=="O" and button9["text"]=="O" or
        button7["text"]=="O" and button5["text"]=="O" and button3["text"]=="O"):
        messagebox.showinfo("GAME OVER","O Is Winner!")
        flag=0
        press=True
        s2=int(s2)
        s2=(s2+1)
        s2=str(s2)
        var1.set(s2)
        reset()
        


    elif flag>=9:
        messagebox.showinfo("GAME OVER","Match Is Draw!")
        flag=0
        press=True
        reset()
    
def resetscore():
    global s1
    global s2
    s1="0"
    s2="0"
    var0.set(s1)
    var1.set(s2)
    
def reset():
    button1["text"]=""
    button2["text"]=""
    button3["text"]=""
    button4["text"]=""
    button5["text"]=""
    button6["text"]=""
    button7["text"]=""
    button8["text"]=""
    button9["text"]=""

#score logic
score=Label(root,text="---<:{ $core }:>---",font=("Verdana","15","normal"))
score.pack(anchor=N)

var0=StringVar()
scoren=Frame(root)
scoren.pack(anchor=W)
scorep1=Label(scoren,text="player X:",font=("Verdana","11","bold"))
scorep1.grid(row=0,column=0)
scorep1c=Label(scoren,textvariable=var0,font=("Segoe UI","14","bold"))
scorep1c.grid(row=0,column=1)
var0.set(s1)

var1=StringVar()
scorep2=Label(scoren,text="\tplayer O:",font=("Verdana","11","bold"))
scorep2.grid(row=0,column=2)
scorep2c=Label(scoren,textvariable=var1,font=("Segoe UI","14","bold"))
scorep2c.grid(row=0,column=3)
var1.set(s2)

#button logic
buttonframe=Frame(root)
buttonframe.pack(padx=5,pady=5)

button1=Button(buttonframe,text="",bd=2,relief = GROOVE  ,font=("Segoe UI","10","bold"),height=5,width=10,command=lambda:check(button1))
button1.grid(row=0,column=0)
button2=Button(buttonframe,text="",bd=2,relief = GROOVE  ,font=("Segoe UI","10","bold"),height=5,width=10,command=lambda:check(button2))
button2.grid(row=0,column=1)
button3=Button(buttonframe,text="",bd=2,relief = GROOVE  ,font=("Segoe UI","10","bold"),height=5,width=10,command=lambda:check(button3))
button3.grid(row=0,column=2)
button4=Button(buttonframe,text="",bd=2,relief = GROOVE  ,font=("Segoe UI","10","bold"),height=5,width=10,command=lambda:check(button4))
button4.grid(row=1,column=0)
button5=Button(buttonframe,text="",bd=2,relief = GROOVE  ,font=("Segoe UI","10","bold"),height=5,width=10,command=lambda:check(button5))
button5.grid(row=1,column=1)
button6=Button(buttonframe,text="",bd=2,relief = GROOVE  ,font=("Segoe UI","10","bold"),height=5,width=10,command=lambda:check(button6))
button6.grid(row=1,column=2)
button7=Button(buttonframe,text="",bd=2,relief = GROOVE  ,font=("Segoe UI","10","bold"),height=5,width=10,command=lambda:check(button7))
button7.grid(row=2,column=0)
button8=Button(buttonframe,text="",bd=2,relief = GROOVE  ,font=("Segoe UI","10","bold"),height=5,width=10,command=lambda:check(button8))
button8.grid(row=2,column=1)
button9=Button(buttonframe,text="",bd=2,relief = GROOVE  ,font=("Segoe UI","10","bold"),height=5,width=10,command=lambda:check(button9))
button9.grid(row=2,column=2)

buttonresetscore=Button(root,text="---| Reset $core |---",font=("Verdana","13","normal"),command=lambda:resetscore())
buttonresetscore.pack(fill=X,side=BOTTOM)

buttonresetboard=Button(root,text="---| Reset Board # |---",font=("Verdana","13","normal"),command=lambda:reset())
buttonresetboard.pack(fill=X,side=BOTTOM)

root.mainloop()
