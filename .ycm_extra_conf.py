def Settings( **kwargs ):
  return {
    'flags': [
              '-x',
              'c++', 
              '-std=c++20', 
              '-Wall', 
              '-Wextra', 
              '-Werror',
              '-Iinclude',
             ]
  }
