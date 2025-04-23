inventory= {}
Prod1= "Mobile"
Prod1_Qty= 5
Prod1_Amt= 20000
Prod1_Relyear= 2020
inventory["Prod1"]=Prod1
inventory["Prod1_Qty"]=Prod1_Qty
inventory["Prod1_Amt"]=Prod1_Amt
inventory["Prod1_Relyear"]=Prod1_Relyear

inventory["Prod2"]="Laptop"
inventory["Prod2_Qty"]= 10
inventory["Prod2_Amt"]= 50000
inventory["Prod2_Relyear"]= 2023    

print(list(inventory.keys()))
"Prod1_Relyear" in inventory 
"Prod2_Relyear" in inventory

print("Prod1_Relyear exists:", "Prod1_Relyear" in inventory)
print("Prod2_Relyear exists:", "Prod2_Relyear" in inventory)

del(inventory["Prod1_Relyear"],inventory["Prod2_Relyear"])
print("After deleting:\n",list(inventory.keys()))