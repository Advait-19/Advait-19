import re

orig='ogfile.txt'
with open(orig,'r') as readfile:
    with open( r"C:\Users\KIIT0001\OneDrive\Desktop\Coding\Pythonscripts\pythonfiles\edtfile.txt",'w+') as editfile:
        for line in readfile:
            editfile.write(line)

        editfile.seek(0,0)
        ed=editfile.read()
        text=re.sub('I','She',ed)
        editfile.seek(0,0)
        editfile.write(text)


with open('edtfile.txt','r') as copyfile:
    
    print('\n',copyfile.read())




