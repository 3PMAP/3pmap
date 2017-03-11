# -*- coding: utf-8 -*-

from setuptools import setup, find_packages


with open('README.md') as f:
    readme = f.read()

with open('LICENSE') as f:
    license = f.read()

setup(
    name = 'RoboticArm',
    version = '0.1.0',
    description = 'Final school project: a robotic arm which can be used as a prothese',
    long_description = readme,
    authors = 'Jelle van Bost, Nathan Guirado & Yochem van Rosmalen',
    author_email = '6283@pierson.nl',
    github_username = 'yochem'
    url = 'https://github.com/yochem/RoboticArm',
    license = license,
    packages = find_packages(exclude=('tests', 'docs'))
)
