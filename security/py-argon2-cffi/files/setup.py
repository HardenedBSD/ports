#!/usr/bin/env python
# setup.py generated by flit for tools that don't yet use PEP 517

from distutils.core import setup

packages = \
['argon2']

package_data = \
{'': ['*']}

package_dir = \
{'': 'src'}

install_requires = \
['argon2-cffi-bindings']

extras_require = \
{":python_version < '3.7'": ['dataclasses'],
 ":python_version < '3.8'": ['typing-extensions'],
 'dev': ['pre-commit',
         'cogapp',
         'tomli',
         'coverage[toml]>=5.0.2',
         'hypothesis',
         'pytest',
         'sphinx',
         'sphinx-notfound-page',
         'furo'],
 'docs': ['sphinx', 'sphinx-notfound-page', 'furo'],
 'tests': ['coverage[toml]>=5.0.2', 'hypothesis', 'pytest']}

setup(name='argon2-cffi',
      version='%%PORTVERSION%%',
      description='The secure Argon2 password hashing algorithm.',
      author=None,
      author_email='Hynek Schlawack <hs@ox.cx>',
      url=None,
      packages=packages,
      package_data=package_data,
      package_dir=package_dir,
      install_requires=install_requires,
      extras_require=extras_require,
      python_requires='>=3.6',
     )
