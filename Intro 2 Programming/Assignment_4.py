# Python Assignment 4
# 
# NOTE - RENAME ASSIGNMENT FILE yourname_Assignment_4.py
# DON'T FORGET THE UNDERSCORES _ IN YOUR FILE NAME
# Hand up only this file and not a folder nor the book.py file

"""
    1.) A file called book.py is included in this folder. It contains
    a string variable called paragraphs. Write code to do the following:
    - Import the book file as a module into this file

    In a single message print the following:
    - "There are X sentences in book."
    - "There are Y words in book."
      Note that hyphenated words e.g. "backward-compatible" count 
      as a single word and names, numbers and years count as
      words as well.
    - The last sentence from paragraph but replace all occurences
      of the word "and" with "&".
"""

print("\nQ 1.")

import book

# Separate by the sentence and word from the string using split()
# Sentences are separated at the full-stop, which will remove the full-stop
separate_sentence = book.paragraphs.split(".")
separate_word = book.paragraphs.split()

# From the arrays declared above, count the sentences and words 
# An empty string will be included after the last full-stop due to split("."), this will be removed from counting sentences
sentence_count = len(separate_sentence)-1
word_count = len(separate_word)

# Declare the last sentence as a variable. [-1] a.k.a last element will be an empty string, therefore using [-2]
last_sentence = separate_sentence[-2]

# Replace 'and' to '&', removed the space at the front
last_sentence_replace = ((last_sentence).replace("and", "&")).strip()

# Added full-stop to last sentence, since it was removed earlier to count sentences with split()
last_sentence_replace += "."

# Printing final message
print(f"There are {sentence_count} sentences in book. There are {word_count} words in book.\n{last_sentence_replace}")


"""
	2.) Tax Collector

	Write code that will ask the user, using an input, what their 
    monthly gross income is. If the user doesn't type in a number 
    print "ERROR not a number" and do not proceed with 
    the calculation.

    - If the user earns less than 500 dollars, the tax 
    taken is 0 and they are in the low tax bracket. Only for these 
    people should you do the following. Ask the user how many 
    children they have. For each child that they have, give them 
    10 dollars in child benefits. If the user does not type in a 
    number they get 0 dollars in child benefits.

    - If the user earns 500 dollars or more but less than  
    700 they are in the medium tax bracket. Tax taken 
    here should be 15% of any sum that is over 500.

    - If the user earns 700 dollars or more they are in the high 
    tax bracket. Tax taken here should be 15% of the sum that is 
    over 500 but less than 700 and 25% of everything over 700.

    The final result should show in a single print the user's 
    gross income, the tax bracket (low, medium or high), total 
    tax, child benefits and net income (gross + child benefits - 
    tax).

    Gross Salary = 400, Bracket = Low,    Tax = 0,     Child Benefits = 20, Net Income = 420, this user has 2 kids
    Gross Salary = 620, Bracket = Medium, Tax = 18,    Child Benefits = 0,  Net Income = 602
    Gross Salary = 905, Bracket = High,   Tax = 81.25, Child Benefits = 0,  Net Income = 823.75
"""

print("\nQ 2.")

# Asking user for salary input
gross_salary = input("What is your gross salary? ")

# Declaring variables for tax amount, child benefits, and tax bracket
tax = 0
child_benefits = 0
bracket = ""

# Checking if user types in a number
try:
    gross_salary = round(float(gross_salary))

# If the user input is not a number
except:
  print("ERROR not a number")
  exit()

# If the salary is less than $500
if gross_salary < 500:
    bracket = "Low"
    num_of_kids = input("How many children do you have? ")

  # Checking if user input for amount of kids for child benefit. If there is no input, it will be 0
    try: 
      num_of_kids = int(num_of_kids)
    except:
      num_of_kids = 0
      
    child_benefits += 10 * num_of_kids

# If the salary is 500 dollars or more but less than 700 
elif gross_salary >= 500 and gross_salary < 700: 
    bracket = "Medium"
    tax += round((gross_salary - 500) * .15)
    child_benefits = 0
    

# If the salary is more than 700   
else:
    bracket = "High"
    tax += (700 - 500) * .15 
    tax += (gross_salary - 700) * .25
    child_benefits = 0
    
    
# Concatenate the print message with corrosponding variables from each condition
output = f"Gross Salary = {gross_salary}, Bracket = {bracket}, Tax = {tax}, Child Benefits = {child_benefits}, Net Income = {gross_salary - tax + child_benefits}"

# Adding the extra string message for low tax bracket condition and printing message
if bracket == "Low":
  output+= f", this user has {num_of_kids} kids"
  print(output)

# Printing message for medium and high tax bracket condition
else: 
  print(output)




    


  

