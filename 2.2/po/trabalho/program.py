from pulp import *
from gym import gym

def program(gym):
    max_time = 500

    model = LpProblem('Gym_Scheduling', LpMinimize)

    start_times = {}
    for client in gym.clients:
        for (machine, _) in gym.durations[client]:
            start_times[(client, machine)] = LpVariable(f'start_{client}_{machine}', lowBound=0, cat='Continuous')

    max_time = LpVariable('max_time', lowBound=0, cat='Continuous')
    model += max_time

    for client in gym.clients:
        for i in range(len(gym.durations[client]) - 1): 
            prev_machine, prev_duration = gym.durations[client][i]
            curr_machine, curr_duration = gym.durations[client][i + 1]
            model += start_times[client, curr_machine] >= start_times[client, prev_machine] + prev_duration

    for machine in gym.machines:
        for client1 in gym.clients:
            for client2 in gym.clients:
                if client1 != client2:
                    for i1, (machine1, duration1) in enumerate(gym.durations[client1]):
                        for i2, (machine2, duration2) in enumerate(gym.durations[client2]):
                            if machine1 == machine2:
                                model += start_times[client1, machine] + duration1 <= start_times[client2, machine] or start_times[client2, machine] + duration2 <= start_times[client1, machine]

    for client in gym.clients:
        for m, duration in gym.durations[client]:
            model += max_time >= start_times[client, m] + duration

    model.solve()
    
    return(model, max_time, start_times)

