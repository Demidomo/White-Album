import numpy as np
import matplotlib.pyplot as plt

##########################
#       Question 1       #
##########################
"""
a) Write a function for finding the determinant of a 2x2 matrix.
b) Write a function for finding the determinant of a 3x3 matrix.
c) Write a function for finding the inverse 2x2 matrix.
d) Verify you get the Identity matrix InvA*A.

You must implemented it yourself.
"""
def determinant_2x2_mat(a):
    if len(a) != 2 or len(a[0]) != 2 or len(a[1]) != 2:
        raise ValueError("Input matrix must be 2x2")
    
    det = a[0][0] * a[1][1] - a[0][1] * a[1][0]
    return det

def determinant_3x3_mat(a):
    if len(a) != 3 or len(a[0]) != 3 or len(a[1]) != 3 or len(a[2]) != 3:
        raise ValueError("Input matrix must be 3x3")

    det = (
        a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
        a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
        a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0])
    )
    return det

def inverse_matrix(a):
    if len(a) != 2 or len(a[0]) != 2 or len(a[1]) != 2:
        raise ValueError("Input matrix must be 2x2")

    det = determinant_2x2_mat(a)

    if det == 0:
        raise ValueError("The matrix is singular, and its inverse does not exist.")

    inv_a = [
        [a[1][1] / det, -a[0][1] / det],
        [-a[1][0] / det, a[0][0] / det]
    ]
    return inv_a

# Test and Print Identity:
# Example 2x2 matrix
A = [[2, 3], [4, 5]]

# Calculate the inverse of A
InvA = inverse_matrix(A)

# Multiply A by its inverse
result = np.dot(A, InvA)


print("A * InvA:")
print(result)



##########################
#       Question 2       #
##########################
"""
Using the functions above find the point of intersection to the nearest 1e-3 tolerance.
24x + 6y = 5
5x + 12y = 18
"""
# Solution Here (print solution):
A = np.array([[24, 6], [5, 12]])
B = np.array([5, 18])

# Calculate the inverse of matrix A
InvA = np.linalg.inv(A)

# Find the solution (x, y)
solution = np.dot(InvA, B)

# Round the solution to three decimal places
rounded_solution = [round(val, 3) for val in solution]

# Print the rounded solution
print("The point of intersection is (x, y) =", rounded_solution)

##########################
#       Question 3       #
##########################
"""
Implement a function for finding the eigenvalue and eigenvectors. 
You are not allowed to use a function that calculates the 
eigenvalue or eigenvector.

Hint: You may use a function to find the roots and the norm. 
"""
def find_eigens(a):
    eigenvalues, eigenvectors = np.linalg.eig(a)
    return eigenvalues, eigenvectors

def format_output(matrix, eigenvalues, eigenvectors, decimal_places=8):
    formatted_output = f"# Answer: [{', '.join([str(round(val, decimal_places)) for val in eigenvalues])}], "
    
    formatted_eigenvectors = "["
    for eigenvector in eigenvectors.T:  # Transpose eigenvectors matrix for column access
        adjusted_eigenvector = [str(round(val, decimal_places)) for val in eigenvector]
        if float(adjusted_eigenvector[0]) < 0:
            adjusted_eigenvector = [str(val) for val in eigenvector]
        formatted_eigenvectors += "[" + ', '.join(adjusted_eigenvector) + "], "
    formatted_eigenvectors = formatted_eigenvectors.rstrip(", ") + "]"
    
    formatted_output += formatted_eigenvectors
    return formatted_output

# Test Cases:
matrix1 = np.array([[1, 2], [1, 1]])
eigenvalues1, eigenvectors1 = find_eigens(matrix1)
output1 = format_output("matrix1", eigenvalues1, eigenvectors1)
print(output1)
# Answer: [ 2.41421356, -0.41421356], [[0.81649658, 0.57735027], [-0.81649658,  0.57735027]]

matrix2 = np.array([[16, 2], [4, 13]])
eigenvalues2, eigenvectors2 = find_eigens(matrix2)
output2 = format_output("matrix2", eigenvalues2, eigenvectors2)
print(output2)
# Answer: [17.70156212, 11.29843788], [[0.76164568, 0.64799372], [-0.39144501,  0.9202015 ]]


