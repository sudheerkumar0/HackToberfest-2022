import random
import math


def nCr(n, r):
    f = math.factorial
    if n < r: return 0
    return f(n) // f(r) // f(n - r)


def random_population(size):
    population = []
    for i in range(size):
        individual = []
        for i in range(8):
            individual.append(random.randint(0, 7))

        population.append(individual)
        # print(mutate(individual))
    return population


def probability(population):
    sum = 0
    probabilities = []
    fitnesses = []
    for individual in population:
        f = fitness(individual)
        fitnesses.append(f)
        sum += f
    for i in range(len(population)):
        print(sum, fitnesses[i], round((fitnesses[i] * 100) / sum, 2))
        probabilities.append(round((fitnesses[i] * 100) / sum, 2))
    return probabilities

def compuateK(population, probabilities, k):
    slist = []
    for i in k:
        rand = random.randint(0, len(population - 1))
        slist.append(rand)
        print(slist)
    return [population[n], population[m], k]

def Selection(population, probabilities, k):
    compuateK(population, probabilities, k)
    minimum = min(probabilities)
    while True:
        n = random.randint(0, len(population) - 1)
        m = random.randint(0, len(population) - 1)
        if probabilities[n] > minimum and probabilities[m] > minimum:
            return [population[n], population[m]]


def crossover(x, y):
    n = len(x)
    c = random.randint(0, n - 1)
    return x[0:c] + y[c:n]


def mutate(x):
    n = len(x)
    c = random.randint(0, n - 1)
    m = random.randint(0, n - 1)
    x[c] = m
    return x


def print_individual(x):
    print("{},  fitness = {}".format(str(x), fitness(x)))


def fitness(x):
    n = len(x)
    state = [0 for i in range(n)]
    for i in range(n):
        state[i] = [0 for j in range(n)]
    for i in range(n):
        state[x[i] - 1][i] = 1
    max_h = nCr(n, 2)
    h = 0
    for i in range(n):
        row = state[i]
        h = h + nCr(sum(row), 2)
    for i in range(n):
        col = []
        for j in range(n):
            col.append(state[j][i])
        h = h + nCr(sum(col), 2)
    rd = []  # right diagonal only
    for i in range(n):
        rd.append(state[i][i])
    h = h + nCr(sum(rd), 2)
    for i in range(n - 1):
        urd = []  # upper right diagonals above right diagonal
        lrd = []  # lower right diagonals below right diagonal
        for j in range(n - 1 - i):
            urd.append(state[j][j + i + 1])
            lrd.append(state[j + i + 1][j])
        h = h + nCr(sum(urd), 2)
        h = h + nCr(sum(lrd), 2)

    ld = []  # Left diagonal only
    for i in range(n):
        ld.append(state[i][n - i - 1])
    h = h + nCr(sum(ld), 2)

    for i in range(n - 1):
        uld = []  # upper left diagonals above left diagonal
        x = n - 2 - i
        for j in range(n - 1 - i):
            uld.append(state[j][x - j])
        h = h + nCr(sum(uld), 2)

    for i in range(1, n):
        lld = []  # Lower left diagonals below left diagonal
        x = n - 1
        for j in range(i, n):
            lld.append(state[j][x])
            x -= 1
        h = h + nCr(sum(lld), 2)
    return max_h - h


def genetic_queen(population):
    new_population = []
    probabilities = probability(population)
    for i in range(len(population)):
        [x, y] = Selection(population, probabilities, 3)
        child = crossover(x, y)
        child = mutate(child)
        if fitness(child) == 28:
            print_individual(child)
            break
        new_population.append(child)
    # end of for
    return new_population


# ----------------- Main Part -----------------

population = random_population(5)
while True:
    print("Genration")
    for chromosome in population:
        print_individual(chromosome)

    population = genetic_queen(population)
