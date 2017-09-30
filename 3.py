import string
x=raw_input('String :')
if x in string.uppercase :
   print"uppercase"
elif x in string.lowercase :
   print"lowercase"
elif x in string.digits :
   print"digits"
else :
   print"others"
