# Corey Biluk
# March 8, 2021

# Demo video Link - https://youtu.be/Otp1WBlJnpU

# This program is a GUI that communicates with an Arduino to control LED outputs and display values for analog/digital inputs.

from tkinter import *
from time import sleep
import serial
from threading import Thread

# Set up serial communication at 9600 baudrate and clear comms line. 
comms = serial.Serial('COM5', 9600)
comms.flush() 
sleep(3)
print("Serial Communication Started")

# Function to control corresponding LED
def LED_control(LED_num):
    comms.write(str(f'LED{LED_num}').encode('utf-8'))    # Send 'LED{#}' message to Arduino with utf-8 encoding
    comms.write(str("\n").encode('utf-8'))               # Send carriage return to signal end of communication
    comms.flush()                                        # Flush serial comms line   

# Function to update/display input values transmitted from Arduino
def update_inputs():
    while True:
        comms.flush()                                    # Flush serial comms line
        arduino_data = comms.readline().decode('utf-8')  # Decode and read data sent from Arduino
        temp = arduino_data.split("/")                   # Split string from arduino into individual values and sotre in temp variable
        
        a0_val = (float(temp[0])/1024) * 5               # Take value for A0 input and convert to volts
        A0.delete(0, END)                                # Clear A0 entry window 
        A0.insert(0, f"{a0_val:.2f} Volts")              # Print A0 value to entry window
                                                         # Reapeats below for inputs A1-A3
        a1_val = (float(temp[1])/1024) * 5
        A1.delete(0, END)
        A1.insert(0, f"{a1_val:.2f} Volts")
        
        a2_val = (float(temp[2])/1024) * 5
        A2.delete(0, END)
        A2.insert(0, f"{a2_val:.2f} Volts")
        
        a3_val = (float(temp[3])/1024) * 5
        A3.delete(0, END)
        A3.insert(0, f"{a3_val:.2f} Volts")
        
        if temp[4] == '0':                               # If transmitted value for D2 is zero/low
            D2.delete(0, END)                            # Clear D2 entry window
            D2.insert(0, "LOW")                          # Print "LOW" to entry window
        else:                                            # If transmitted value for D2 is one/high
            D2.delete(0, END)                            # Clear D2 entry window
            D2.insert(0, "HIGH")                         # Print "HIGH" to entry window
                                                         # Repeats below for inputs D3-D5
        if temp[5] == '0':
            D3.delete(0, END)
            D3.insert(0, "LOW")
        else:
            D3.delete(0, END)
            D3.insert(0, "HIGH")
                
        if temp[6] == '0':
            D4.delete(0, END)
            D4.insert(0, "LOW")
        else:
            D4.delete(0, END)
            D4.insert(0, "HIGH")
            
        if temp[7] == '0':
            D5.delete(0, END)
            D5.insert(0, "LOW")
        else:
            D5.delete(0, END)
            D5.insert(0, "HIGH")
   
###############
# Main Function
###############
if __name__ == '__main__':
        
    # Create GUI app, change window icon, and set window size
    root = Tk()
    root.title("IO Data Acquisition System GUI")
    root.iconbitmap("cat3.ico")
    root.geometry('280x320')

    # GUI Title Label
    title = Label(root, text="IO Data Acquisition System GUI", width=30, font=20)
    title.grid(row=0, column=0, columnspan=2)

    ########################
    # TOP LEFT (LED Outputs)
    ########################
    top_left_frame = LabelFrame(root, text="Outputs", padx=10, pady=23)
    top_left_frame.grid(row=1, column=0)

    # Create Buttons (lambda: allows a value to be passed to the function when button is pressed)
    LED1_button = Button(top_left_frame, text="LED 1", command=lambda: LED_control(1))
    LED1_button.grid(row=0, column=0, padx=1, pady=1)
    LED2_button = Button(top_left_frame, text="LED 2", command=lambda: LED_control(2))
    LED2_button.grid(row=0, column=1, padx=1, pady=1)
    LED3_button = Button(top_left_frame, text="LED 3", command=lambda: LED_control(3))
    LED3_button.grid(row=1, column=0, padx=1, pady=1)
    LED4_button = Button(top_left_frame, text="LED 4", command=lambda: LED_control(4))
    LED4_button.grid(row=1, column=1, padx=1, pady=1)

    ###########################
    # TOP RIGHT (Analog Inputs)
    ###########################
    top_right_frame = LabelFrame(root, text="Analog Inputs", padx=10, pady=9)
    top_right_frame.grid(row=1, column=1)

    # Create analog input entry box labels
    A0_label = Label(top_right_frame, text="A0")
    A0_label.grid(row=0, column=0)
    A1_label = Label(top_right_frame, text="A1")
    A1_label.grid(row=1, column=0)
    A2_label = Label(top_right_frame, text="A2")
    A2_label.grid(row=2, column=0)
    A3_label = Label(top_right_frame, text="A3")
    A3_label.grid(row=3, column=0)

    # Create analog input entry boxes
    A0 = Entry(top_right_frame, width=13, justify=CENTER)
    A0.grid(row=0, column=1)
    A1 = Entry(top_right_frame, width=13, justify=CENTER)
    A1.grid(row=1, column=1)
    A2 = Entry(top_right_frame, width=13, justify=CENTER)
    A2.grid(row=2, column=1)
    A3 = Entry(top_right_frame, width=13, justify=CENTER)
    A3.grid(row=3, column=1)

    ##############################
    # BOTTOM LEFT (Digital Inputs)
    ##############################
    bottom_left_frame = LabelFrame(root, text="Digital Inputs",padx=13, pady=10)
    bottom_left_frame.grid(row=2, column=0)

    # Create digital input entry box labels
    D2_label = Label(bottom_left_frame, text="D2")
    D2_label.grid(row=0, column=0)
    D3_label = Label(bottom_left_frame, text="D3")
    D3_label.grid(row=1, column=0)
    D4_label = Label(bottom_left_frame, text="D4")
    D4_label.grid(row=2, column=0)
    D5_label = Label(bottom_left_frame, text="D5")
    D5_label.grid(row=3, column=0)

    # Create digital input entry boxes
    D2 = Entry(bottom_left_frame, width = 7, justify=CENTER)
    D2.grid(row=0, column=1, padx=5, pady=5)
    D3 = Entry(bottom_left_frame, width = 7, justify=CENTER)
    D3.grid(row=1, column=1, padx=5, pady=5)
    D4 = Entry(bottom_left_frame, width = 7, justify=CENTER)
    D4.grid(row=2, column=1, padx=5, pady=5)
    D5 = Entry(bottom_left_frame, width = 7, justify=CENTER)
    D5.grid(row=3, column=1, padx=5, pady=5)

    ############################
    # BOTTOM RIGHT (Exit Button)
    ############################
    # Create exit button 
    exit_button = Button(root, text="Exit", height=2, width=8, command = root.destroy)
    exit_button.grid(row=2, column=1, sticky=S+S+E)

    # Create and start threads
    t2 = Thread(target = update_inputs)
    t2.start()
    
    ###############
    # App Main Loop
    ###############
    root.mainloop()

    # Close serial communications
    comms.close()
