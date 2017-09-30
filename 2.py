print"DIVYA "+"ROSE RAJU"
import string
x=raw_input("enter a sentence :")
y=raw_input("enter a character :")
if string.find(x,y)!=-1 :
  print"%s is present in %s"% (y,x)
else :
  print"not present"
