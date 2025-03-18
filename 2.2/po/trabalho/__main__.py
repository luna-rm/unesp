#Luna Ricieri Marchi - 231024801

from pulp import *
from gym import gym
from program import program

center = gym(
    clients = ['C1', 'C2', 'C3', 'C4', 'C5', 'C6'],
    machines = [0, 1, 2, 3, 4, 5],
    durations = {
        'C1': [(2, 1), (0, 3), (1, 6), (3, 7), (5, 3), (4, 6)],
        'C2': [(1, 8), (2, 5), (4, 10), (5, 10), (0, 10), (3, 4)],
        'C3': [(2, 5), (3, 4), (5, 8), (0, 9), (1, 1), (4, 7)],
        'C4': [(1, 5), (0, 5), (2, 5), (3, 3), (4, 8), (5, 9)],
        'C5': [(2, 9), (1, 3), (4, 5), (5, 4), (0, 3), (3, 1)],
        'C6': [(1, 3), (3, 3), (5, 9), (0, 10), (4, 4), (2, 1)]
    }
);

compact = gym(
    clients = ['C1', 'C2', 'C3', 'C4', 'C5', 'C6', 'C7', 'C8', 'C9', 'C10'],
    machines = [0, 1, 2, 3, 4],
    durations = {
        'C1': [(1, 21), (0, 53), (4, 95), (3, 55), (2, 34)],
        'C2': [(0, 21), (3, 52), (4, 16), (2, 26), (1, 71)],
        'C3': [(3, 39), (4, 98), (1, 42), (2, 31), (0, 12)],
        'C4': [(1, 77), (0, 55), (4, 79), (2, 66), (3, 77)],
        'C5': [(0, 83), (3, 34), (2, 64), (1, 19), (4, 37)],
        'C6': [(1, 54), (2, 43), (4, 79), (0, 92), (3, 62)],
        'C7': [(3, 69), (4, 77), (1, 87), (2, 87), (0, 93)],
        'C8': [(2, 38), (0, 60), (1, 41), (3, 24), (4, 83)],
        'C9': [(3, 17), (1, 49), (4, 25), (0, 44), (2, 98)],
        'C10': [(4, 77), (3, 79), (2, 43), (1, 75), (0, 96)]
    }
);

if __name__ == '__main__':
    print('Qual academia deseja otimizar?')
    print('  0 - Centro')
    print('  1 - Compacta')
    
    c = '-1'
    
    while(c != '0' and c != '1'):
        c = input();
    
    if c == '0':
        resolve = center
    else:
        resolve = compact
        
    model, max_time, start_times = program(resolve)
    
    for client in resolve.clients:
        print('\nCronograma para ' + str(client) + ':')
        for i, (machine, duration) in enumerate(resolve.durations[client]):
            start_time = start_times[client, machine].varValue
            print('  Aparelho ' + str(machine) + ', início: ' + str(start_time) + ', duração: ' + str(duration) + ' minutos')
    print('\n\nTempo total mínimo:', max_time.varValue)
