# Python File Handling


"""
	1.) Open and read the file q1_text.txt. Print out the entire
	contents of the file.
"""
print("\nQ 1.")

my_file = open("q1_text.txt")
print(my_file.read())

"""
	2.) Open and read the file q2_text.txt. Print out only the
	first and last line in this file.
"""
print("\nQ 2.")

with open("q2_text.txt", "r") as file:
    first_line = file.readline()
    for last_line in file:
        pass

print(first_line)
print(last_line)
"""
	3.) Open up file q3_text.txt and at the end of it write a
	new line "- From <your name here>". Make sure not to delete 
	any of the text inside of it.
"""
print("\nQ 3.")

# Write Code here
new_line = "- From Santa"
with open("q3_text.txt", "a") as a_file:
    a_file.write("\n")
    a_file.write(new_line)


def restore_q3():
    print('Q3. HAS BEEN RESTORED')
    with open('q3_text.txt', mode='w', encoding='utf-8') as f3:
        f3.write("""Dear Santa,
This year I would like a bike
because my last one was stolen
on Granville Island!""")


# Call restore_q3() if you accidentally delete the file
# restore_q3()
#############


"""
	4.) Open up file q4_text.txt and print the average of all
	the numbers that appear in the file. The numbers are all 
	separated by a single space " " each
"""
print("\nQ 4.")


data = []
with open(r'q4_text.txt') as f:
    for line in f:
        fields = line.split()
        rowdata = map(float, fields)
        data.extend(rowdata)

print(sum(data)/len(data))



"""
	5.) Create a new file called q5_answer.txt and write
	2 lines in it reading "I made this with Python" and
	"A new file gets created if no file in the directory
	has the same name as it!". After this is created, print
	the line "q5_answer is made"
"""
print("\nQ 5.")

f = open("q5_answer.txt", "a")
f.write("I made this with Python\n")
f.write("A new file gets created if no file in the directory has the same name as it!")

print("q5_answer is made")



"""
	6.) q6_tsv.tsv is a tab separated values file. It
	contains words separated by tabs \t on a single line. 
	Count how many words there are in the file and print it. 
	Also, to the end of the file add the following "there are
	X words in this file".

"""
print("\nQ 6.")

file = open('q6_tsv.tsv', 'r')
read_data = file.read()
per_word = read_data.split()

print('Total Words:', len(per_word))

def restore_q6():
    print('Q6 HAS BEEN RESTORED')
    with open('q6_tsv.tsv', mode='w', encoding='utf-8') as f6:
        f6.write('cat\tbat\that\tmat\tfat\tchat')


# Call restore_q6() if you accidentally delete the file
# restore_q6()
#############


"""
	7.) Print how many times the word "Canada" appears in 
	the q7_text.txt file. Replace all appearances of the word 
	Canada in the file with the word "CENSORED". You must 
	overwrite the file when doing this.
"""
print("\nQ 7.")

word = "Canada"
count = 0
with open("q7_text.txt", 'r') as f:

	for line in f:
		words = line.split()
		for i in words:
			if(i==word):
				count=count+1


print("Occurrences of the word Canada", word, ":", count)

# Read in the file
with open('file.txt', 'r') as file :
  filedata = file.read()





def restore_q7():
    print('Q7 HAS BEEN RESTORED')
    with open('q7_text.txt', mode='w', encoding='utf-8') as f7:
        f7.write("""Canada is a country in North America. 
Canada's capital is Ottawa, and its three largest 
metropolitan areas are Toronto, Montreal, and Vancouver.
Indigenous peoples have continuously inhabited what is 
now Canada for thousands of years.
In 1867, with the union of three British North American 
colonies through Confederation, Canada was formed as a 
federal dominion of four provinces.""")

# Call restore_q7() if you accidentally delete the file
# restore_q7()
#############
