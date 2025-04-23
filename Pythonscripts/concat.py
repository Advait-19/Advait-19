Champions=['Italy','Spain','Argentina']
Comp=['Euros','Nations League','Copa America']
def concat(list,y):
    list.extend(y)
    return list
print(concat(Champions,Comp))