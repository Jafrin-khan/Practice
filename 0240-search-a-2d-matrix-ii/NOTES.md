row, col = 0, len(matrix[0])-1
while row < len(matrix) and col >= 0:
if matrix[row][col] == target:
# target found
return True
elif matrix[row][col] < target:
# current element is smaller than target, move down one row
row += 1
else:
# current element is greater than target, move left one column
col -= 1
# target not found
return False