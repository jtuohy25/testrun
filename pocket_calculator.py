#mge2zx Jenna Tuohy

def get_value():
    '''
    outputs the current value of the calculator
    :return:stored value of the calculator at the time the function is called
    '''
    return value

def clear(value_new = 0):
    '''
    clears the calculator value back to 0 or the value the user inputs
    :param value_new: new number stored as 'value'
    :return: new 'value' and new 'series' without any previous operations
    '''
    global operation
    global argument
    operation = ''
    argument = 0
    global value
    global series
    value = value_new
    series = str(value_new)
    return value
    return series

def step(math_operator, int_argument):
    '''
    performs a mathematical operation on the current value stored in the calculator
    :param math_operator: type of operation that is to be performed on the value
    :param int_argument: number that is to be added, subtracted, multiplied, or divided by the current value of the calculator
    :return: new value of 'value' after the operation takes place
    '''
    global value
    global operation
    global argument
    operation = math_operator
    argument = int_argument
    if math_operator == '+':
        value = value + int_argument
        helper(math_operator, int_argument)
    elif math_operator == '-':
        value = value - int_argument
        helper(math_operator, int_argument)
    elif math_operator == '*':
        value = value * int_argument
        helper(math_operator, int_argument)
    elif math_operator == '//':
        value = value // int_argument
        helper(math_operator, int_argument)
    return value

def repeat():
    '''
    repeates the last operation performed by the 'step' function
    :return: value of 'value after the 'step' operation is repeated
    '''
    global value
    global operation
    global argument
    if value == 0:
        return value
    else:
        step(operation, argument)
        return value

def helper (math, number_used):
    '''
    updates the 'series' string with the pervious peration ran in the step function
    :param math: operation executed
    :param number_used: number that is to be added, subtracted, multiplied, or divided by the current value of the calculator
    :return: the updated series with all operations before the clear function is called
    '''
    global series
    series = '(' + series + ')' + math + str(number_used)
    return series

def get_expr():
    '''
    outputs every operation that was run on the calculator before calling clear
    :return:series of operations run by the calculator
    '''
    if series == '0':
        return series
    else:
        expression = series
        return expression


value = 0
operation = ''
argument = 0
series = '0'

