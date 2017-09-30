import string
import glob
import pickle 
def djfcars():
  n=input("enter number of cars to be added:")
  for i in range(n):
    name=raw_input("Car Name:")
    a=[]
    a.append(raw_input("Model:"))
    a.append(input("price:"))
    a.append(raw_input("colour:"))
    a.append(input("In stock :"))
    d[name]=a
def mainmenu():
  print"\t","\t","MAIN MENU"
  print
  print"1-Enquiry"
  print"2-Car booking"
  print"3-Exit"
  x=input("Enter your option :")
  if x==1 :
     enquiry()
  elif x==2 :
     carbooking()
  elif x==3 :
     exit()
  else :
    print"Invalid Option"
def enquiry() :
  y=raw_input("Enter car name of your choice :")
  t=d.has_key(y)
  if t==0 :
    print"Car Unavailable"
  else:
    l=[]
    l=d[y]   
    print"Model :",l[0]
    print"Price :",l[1]
    print"colour :",l[2]
    print"In Stock :",l[3]
    if l[3]==0 :
       print"car out of stock"
  print"Check another car :"
  print"1-yes"
  print"2-No"
  p=input("enter your option :")
  if p==1 :
    enquiry()
  elif p==2 :
    mainmenu()
  else :
    print"Invalid Option"
def carbooking() :
  y=raw_input("Enter car name of your choice :")
  t=d.has_key(y)
  if t==0 :
    print"Car Unavailable"
  else:
    l=[]
    l=d[y]   
    print"Model :",l[0]
    print"Price :",l[1]
    print"colour :",l[2]
    print"In Stock :",l[3]
    if l[3]==0 :
       print"car out of stock" 
  if t==0 or l[3]==0 : 
    print"Available Cars :"
    print d.keys()
    y=input("choose a car :")
  print"Do you want to proceed to booking :"
  print"1-yes"
  print"2-No"
  r=input("enter your option :")
  if r==2 :
    mainmenu()
  elif r==1 :
    f1=open("file.txt","w")
    print"Customer Details :"
    cname=raw_input("Name :")
    cadd=raw_input("Address :")
    cno=input("Mobile number :")
    cmodel=y
    cmail=raw_input("E-mail :")
    adv=input("Advance paid(if any,) :")
    pickle.dump((cname,cadd,cno,cmodel,cmail,adv),f1)
    f1.close()
    l[3]=l[3]-1
    print"Succesfully Booked",y
    print"Thank You"            
d={}
djfcars()
print"\t","\t","MICRO PROJECT USING PYTHON"
print"\t","\t","CAR SHOWROOM MANAGEMENT"
print"TEAM MEMBERS","\t","\t","REG. NO."
print"Divya Rose Raju","\t","U1503067"
print"Joel Kurian","\t","\t","U1503093"
print"Farhan E Abdul Salam","\t","U1503072"
print"CLASS: S1 CSE-BETA"
print"Under the guidance of :Ms Athira and Mr Varghese "
print
print"\t","\t","WELCOME TO DJF CARS WORLD"
mainmenu()

