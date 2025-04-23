'''
example="file1.txt"
file=open(example,'w+')
file.write("\nWelcome to Python")
filecontent=file.read()
print(filecontent)
file.close()


example="file1.txt"
file=open(example,'r+')
file.write("\nThis is my first file")
filecontent=file.read()
print(filecontent)
file.close()
'''


with open('file1.txt', 'r+') as testwritefile:
    data = testwritefile.readlines()
    testwritefile.seek(0,0) #write at beginning of file
   
    testwritefile.write("Line 1\n")
    testwritefile.write("Line 2\n")
    testwritefile.write("Line 3\n")
    testwritefile.write("finished\n")
    #Uncomment the line below
    testwritefile.truncate(2000)
    testwritefile.seek(0,0)
    print(testwritefile.read())