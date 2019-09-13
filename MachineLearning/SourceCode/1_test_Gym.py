import gym

# select game env and init it
env = gym.make('Breakout-v0')
env.reset()

for _ in range(1000):
    env.render()
    env.step(env.action_space.sample())