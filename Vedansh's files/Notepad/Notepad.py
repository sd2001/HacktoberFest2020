from tkinter import *
from tkinter.filedialog import *
from tkinter import messagebox
import os




# Basic Tkinter setup
# We will create a window widget with the title Notepad
window = Tk()
window.title("Notepad")

# With this we will give an icon to the program and we will give a geometry to the window in the form widthxheight
window.wm_iconbitmap("notepad_icon.ico")
window.geometry("1280x720")

# With this we will be creating a lower limit of resizing the window in the format of width,height
window.minsize(733,434)

# Adding text area to the window
text_area = Text(window, font="Consolas 11", wrap=NONE, undo=True)

# Now we will appoint the file variable as none 
# But afterwards when we open a file on the window then the variable would be assigned the name of that particular file which is opened.
# And also we will fill the window fully with the text area as it resizes
file = None
text_area.pack(expand=True,fill=BOTH)



# First here we will make all the functions related to the features added in the menu bar        

def new_file():
    global file
    window.title("Untitled - Notepad")
    file = None
    text_area.delete(1.0, END)





def open_file():
    global file
    file = askopenfilename(defaultextension=".txt",filetypes=[("All Files", "*.*"),("Text Documents", "*.txt")])
    if file == "":
        file = None
    
    else:
        window.title(os.path.basename(file) + " - Notepad")
        text_area.delete(1.0, END)
        f = open(file, "r")
        text_area.insert(1.0, f.read())
        f.close()
    

    



def save_file():
    global file
    if file == None:
        file = asksaveasfilename(initialfile = 'Untitled.txt', defaultextension=".txt",filetypes=[("All Files", "*.*"),("Text Documents", "*.txt")])
        if file =="":
            file = None
        else:
            #Save as a new file
            f = open(file, "w")
            f.write(text_area.get(1.0, END))
            f.close()
            window.title(os.path.basename(file) + " - Notepad")
    else:
        # Save the file
        f = open(file, "w")
        f.write(text_area.get(1.0, END))
        f.close()
        




def close_file():
    text_area.delete('1.0', END)
    window.title("Notepad")

        

        
    
def exit_file():
    if messagebox.askokcancel("Save Changes", "Do you want to save changes?"):
        save_file()
        window.destroy
    elif messagebox.askokcancel("Quit", "Do you want to quit?"):
        window.destroy()




def cut():
    text_area.event_generate(("<<Cut>>"))


def copy():
    text_area.event_generate(("<<Copy>>"))


def paste():
    text_area.event_generate(("<<Paste>>"))


def select_all():
    text_area.tag_add('sel', '1.0', 'end')


def delete():
    text_area.delete(0.0, END)


def deselect_all():
    text_area.tag_remove("sel",'1.0','end')




def about():
    messagebox.showinfo("Notepad", "This is a GUI Notepad created using python by Vedansh")



# Creating a menubar widget
menu = Menu(window)

# Now we will make a file menu inside the menubar
file = Menu(menu, tearoff=0)

# Now we will give the file widget features
file.add_command(label="New File", accelerator="Ctrl+N", command=new_file)
file.add_command(label="Open File", accelerator="Ctrl+O", command=open_file)
file.add_command(label="Save File", accelerator="Ctrl+S", command=save_file)
file.add_separator()
file.add_command(label="Close File", command=close_file)
file.add_command(label="Exit", accelerator="Alt+F4", command=exit_file)


# Now we will put all these commands inside the file widget in the menu bar
menu.add_cascade(label="File", menu=file)



# Now we will make an edit menu in the menu bar
edit = Menu(menu,tearoff=0)

# Now we will give the edit widget featues
edit.add_command(label="Undo", accelerator='Ctrl+Z', command=text_area.edit_undo)
edit.add_command(label="Redo", accelerator='Ctrl+Y', command=text_area.edit_redo)
edit.add_separator()
edit.add_command(label="Cut", accelerator='Ctrl+X', command=cut)
edit.add_command(label="Copy", accelerator='Ctrl+C', command=copy)
edit.add_command(label="Paste", accelerator='Ctrl+V', command=paste)
edit.add_command(label="Delete", accelerator='Del', command=delete)
edit.add_separator()
edit.add_command(label="Select all", accelerator='Ctrl+A', command=select_all)
edit.add_command(label="Deselect all", accelerator='Ctrl+LShift+Space', command=deselect_all)

# Now we will put all these commands in the edit widget in the menu bar
menu.add_cascade(label="Edit", menu=edit)




# Now we will make a help menu in the menu bar
_help = Menu(menu, tearoff=0)
_help.add_command(label="About", command=about)

# Now we will put all these commands in the help widget in the menubar
menu.add_cascade(label="Help", menu=_help)

# This wil add menu to the menu bar
window.config(menu=menu)

# Now we will add horizontal and vertical scroll bar to the text editor
scroll1=Scrollbar(text_area, orient='vertical')
scroll1.pack(side=RIGHT, fill=Y)
scroll1.config(command=text_area.yview)
text_area.config(yscrollcommand=scroll1.set)

scroll2=Scrollbar(text_area, orient='horizontal')
scroll2.pack(side=BOTTOM, fill=X)
scroll2.config(command=text_area.xview)
text_area.config(xscrollcommand=scroll2.set)

    
window.mainloop()