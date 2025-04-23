album1=set(['Thriller','AC/DC','Back in Black'])
album2=set(['AC/DC','The Dark Side of Moon','Back in Black'])
album3=album1 & album2
print(album3)

print(album1.issubset(album3))