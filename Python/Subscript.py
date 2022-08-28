import paho.mqtt.client as mqtt
import serial
import json


ser = serial.Serial("/dev/rfcomm2", 9600)
Server="linux.chenyun.org"
Port=1883
topic="QUTGP/sblock/level12/#"
temperatureStandard= 25
humiditystandard=60


def on_connect(client, userdata, flags, rc): 
    if rc == 0:
        print("Connected to MQTT Broker!")
    else:
        print("Failed to connect, return code %d\n", rc)
    client.subscribe(topic) 

def on_message(client, userdata, msg):       
    # Func for Sending msg 
    #print(msg.topic+" "+str(msg.payload))
    data=str(msg.payload)
    shabi=data.split("'")
    #print(shabi[1])
    controlAlarm (shabi[1])
# def alert_On():

# def alert_Off():
    
def controlAlarm(data):
    print(data)
 
    RawData = json.loads(data)
    RawData["title"]
    #print (mes_to_dict["title"])
    if(RawData["roomNO"]=="*ROOM1201*"):
        if (RawData["title"]=="Temperature"):
            if(float(RawData["degree"])>temperatureStandard):
                ser.write(bytes("1", 'utf-8'))
           
               
        if (RawData["title"]=="Humidity"):
            if(float(RawData["degree"])>humiditystandard) :
                ser.write(bytes("1", 'utf-8'))
           
                
    if(RawData["roomNO"]=="*ROOM1202*"):
        if (RawData["title"]=="Temperature"):
            if(float(RawData["degree"])>temperatureStandard):
                ser.write(bytes("2", 'utf-8'))
         
              
        if (RawData["title"]=="Humidity"):
            if(float(RawData["degree"])>humiditystandard):
               ser.write(bytes("2", 'utf-8'))
          
              
client = mqtt.Client() 
client.on_connect = on_connect 
client.on_message = on_message 
client.connect(Server, Port, 60) 
client.loop_forever()