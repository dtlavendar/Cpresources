board = [[" " for j in range(7)] for i in range(6)]
player = 0
def print_board():
  for i in range(6):
    for j in range(6):
      print(board[i][j], end="|") 
    print(board[i][6])
    if i < 5:
      print("-------------")

def full(slot):
  for i in range(6):
    if board[i][slot] == " ":
      return False
  return True

  
def check_board():
  good = True
  for i in range(6):
    for j in range(7):
      if board[i][j] == " ":
        continue
      works = True
      if i + 3 >= 6:
        break
      for k in range(1,4):
        if board[i + k][j] != board[i][j]:
          works = False
          break
      good &= not works
          
  for i in range(6):
    for j in range(7):
      if board[i][j] == " ":
        continue;
      works = True
      if j + 3 >= 7:
        break
      for k in range(1,4):
        if board[i][j + k] != board[i][j]:
          works = False
          break
      good &= not works

  for i in range(6):
    for j in range(7):
      if board[i][j] == " ":
        continue;
      works = True
      if j + 3 >= 7 or i + 3 >= 6:
        break
      for k in range(1,4):
        if board[i + k][j + k] != board[i][j]:
          works = False
          break
      good &= not works
  for i in range(6):
    for j in range(7):
      if board[i][j] == " ":
        continue;
      works = True
      if j + 3 >= 7 or i - 3 < 0:
        break
      for k in range(1,4):
        if board[i - k][j + k] != board[i][j]:
          works = False
          break
      good &= not works

  return not good

def game_draw():
  fulfilled = True
  for i in range(7):
    if not full(i):
      fulfilled = False
  return fulfilled&check_board()

def place_chip(slot, current_player):
  choice = "XO"[current_player]
  assert not full(slot)
  for i in range(5,-1,-1):
    if board[i][slot] == " ":
      board[i][slot] = choice
      return

def ask_player(current_player):
  slot = int(input("Player #{}: Pick a slot of the board: [1, 7] \n".format(current_player+1)))
  return slot - 1
  
while not check_board() and not game_draw():
  print_board()
  spot = ask_player(player)
  while full(spot):
    ask_player(player)
  place_chip(spot,player)
  player ^= 1
print_board()
print("Game Draw. Please Play again..." if game_draw() else "Game win! Player {} wins!".format((player^1)+1))

 
