# Python Loops

"""
	1.) Below is a tuple, list and dictionary. Write a simple for loop
	for each one, that prints off each value in each of them
"""
print("\nQ 1.")

my_list = ["list1", "list2"]
my_tuple = ("tuple1", "tuple1")
my_dict = {"A": "word", "B": 1, "C": 3}


for list in my_list:
	print(list)

for tuple in my_tuple:
	print(tuple)

for dict in my_dict:
	print(dict)




"""
	2.) Loop through this string and for each character print out
	"x is a letter in y" where x is the letter and y is the contents
	of the string
"""
print("\nQ 2.")

my_string = "abcd"

for string in my_string: 
	print(f"{string} is a letter in {my_string}")


"""
	3.) Loop through this string and using a single print(), print
	out the string but have all vowels capitalized. You'll need to
	create a new empty string and add each letter. If the letter is
	a vowel use .upper() to uppercase it
"""
print("\nQ 3.")

my_other_string = "abcdefghijklmnopqrstuvwxyz"

other_other_string = ""

for string in my_other_string:
	if string in ['a','e','u','i','o']:
		other_other_string += string.upper()
	else: 
		other_other_string += string.lower()

print(other_other_string)



"""
	4.) Write a for loop that prints the numbers from 0 to 5
"""
print("\nQ 4.")

for num in range(0,6):
	print(num)

"""
	5.) Write a for loop that prints the numbers from 5 to 20
	in increments of 3. That is to print 5 8 11 14 17 20. Make
	sure to print this all off in a single print()
"""
print("\nQ 5.")

for number in range(5,21,3):
	print(number)

"""
	6.) Create a new list that contains only the planet strings
	from planet_list that have 5 characters or less. Print out
	that list at the end.
"""
print("\nQ 6.")

planet_list = ["Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"]

new_list = []
for planet in planet_list:
	if len(planet) <= 5:
		new_list.append(planet)

print(new_list)


"""
	7.) Write code that removes all items from the list that are
	'N'. Decide on what loop is best to use in thie situation. Also
	count how many times 'N' appears in the list. Finally print the
	new list and print "X number of Ns were removed from the list"
"""
print("\nQ 7.")

list_to_remove_items = ['N', 'A', 'B', 'N', 'N', 'M', 'B', 'W', 'A', 'N', 'L', 'S', 'H', 'D', 'N', 'N', 'P']

final_list = []
n_count = 0

for items in list_to_remove_items:
	if items != 'N':
		final_list.append(items)
	else: 
		n_count += 1

print(f"{final_list}\n{n_count} number of Ns were removed from the list")



"""
	8.) Write code that asks the user to input a number. If they
	don't input a number, keep asking them to do it until they
	do. When they do, print the sentence "Half of your number is X"
	where X is half of the number.
	Use a while loop. Use try...except to test if input is an integer
"""
print("\nQ 8.")




while True:
	try:
		user_input = int(input("Please input a number "))
		half_number = user_input / 2
		print(f"Half of your number is {half_number}")
		
	except ValueError: 
		print("Not a number. Please input a number ")
		continue
		

	else: 
		break

