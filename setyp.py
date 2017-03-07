# -*- coding: utf-8 -*-

from setuptools import setup, find_packages


with open('README.md') as f:
    readme = f.read()

with open('LICENSE') as f:
    license = f.read()

setup(
    name = 'RoboticArm',
    version = '0.1.0',
    description = 'PWS making a robotic arm used as a prothesis.',
    long_description = readme,
    author1 = 'Yochem van Rosmalen',
    author2 = 'Jelle Bost'
    author3 = 'Nathan Guirado'
    author_email = '6283@pierson.nl',
    github_username = 'yochem'
    url = 'https://github.com/yochem/RoboticArm',
    license = license,
    packages = find_packages(exclude=('tests', 'docs'))
)
