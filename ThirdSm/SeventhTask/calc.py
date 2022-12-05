#!/bin/python3
prob = [ 0.0833333, 0.0416667, 0.0416667, 0.0416667, 0.0833333, 0.0416667, 0.0833333, 0.0833333, 0.0416667, 0.0416667, 0.125, 0.0833333, 0.0833333, 0.0416667, 0.0416667, 0.0416667]
code = [ "1110", "0110", "10111", "11010", "1010", "01111", "1100", "000", "10110", "01110", "100", "010", "1111", "11011", "0011", "0010"]

def calc(prob, code):
    sm = 0
    avg = 0
    for x in code:
        avg += x
    print(avg)
    avg /= len(code)
    print(avg)
    for i in range(0, len(prob)):
        print(f"{prob[i]} * {((code[i] - avg)**2)} = {prob[i] * ((code[i] - avg)**2)}")
        sm += prob[i] * ((code[i] - avg)**2)
    return sm

if __name__=='__main__':
    code = [len(i) for i in code]
    print(code)
    print(calc(prob, code))

