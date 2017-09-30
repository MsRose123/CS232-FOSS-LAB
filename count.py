print "D"+"ivya"
import string
x=raw_input("enter a string :")
ch=0
count=0

for c in x :
    ch=ch+1
    if c ==" " :
      count=count +1
print"no. of characters=",ch
if count==0 :
  print"no. of words=",count
else :
  print"no. of words=",count+1
  
 
