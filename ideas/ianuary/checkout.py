
def nc2(i):
    return i * (i - 1) / 2

def get_icount(a):
    twos = 0
    total = 0
    for i in range(len(a)):
        if a[i] == '2':
            twos += 1
        elif a[i] == '4':
            total += nc2(twos)
        else:
            return -1
    return total

def split_into_answers(lines):
    answers = [[]]
    for line in lines:
        answers[-1].append(line)
        if line != 'YES':
            answers.append([])
    return answers[:-1]

def checker(student_output_file, input_path, output_path):
    try:
        actual = student_output_file.read().split()
    except:
        return 0.0

    with open(output_path) as f:
        expected = f.read().split()

    with open(input_path) as f:
        inputss = [i.strip().split() for i in f.readlines()[1:]]
        for i in range(len(inputss)):
            inputss[i] = [int(j) for j in inputss[i]]

    actuals = split_into_answers(actual)
    expecteds = split_into_answers(expected)

    for line in zip(inputss, actuals, expecteds):
        inputs_n = line[0][0]
        inputs_m = line[0][1]
        actual = line[1]
        actual_verdict = actual[0] 
        expected = line[2]
        expected_verdict = expected[0]
      
        # if expected is YES then actual should be YES 
        if expected_verdict != actual_verdict:
            print(expected_verdict, actual_verdict)
            return 0.0

        # if they are both NO, then there will be no following arr
        if expected == ['NO'] and actual == expected:
            continue

        actual_arr = line[1][1]
        expected_verdict = line[2][0]

        if len(actual_arr) != inputs_n:
            print("bad len", len(actual_arr), inputs_n)
            return 0.0
        
        if get_icount(actual_arr) != inputs_m:
            print("wrong icount", get_icount(actual_arr), inputs_m)
            return 0.0

    return 1.0


