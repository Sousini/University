def robot(comandos):
    current_pos = (0,0)
    current_dir_id = 0
    rectangles = []
    temp_rect = (0,0,0,0) #(min x, min y, max x, max y)
    #posiçoes = ["Up","Right","Down","Left"]
    for x in comandos:
      print(x)
      if x == "E":
        if current_dir_id != 0:
          current_dir_id-=1
        else:
          current_dir_id=3   
      elif x == "D":
        if current_dir_id != 3:
          current_dir_id+=1
        else:
          current_dir_id=0
      elif x == "A":
        current_pos = move_cur_dir(current_pos, current_dir_id)
        temp_rect = save_minmax(current_pos, temp_rect)
      else:
        rectangles.append(temp_rect)
        #reset values
        temp_rect = (0,0,0,0)
        current_pos = (0,0)
        current_dir_id = 0
    return rectangles

def save_minmax(current_pos, temp_rect):
  current_x = current_pos[0]
  current_y = current_pos[1]
  #temp_rect = (0,0,0,0) #(min x, min y, max x, max y)
  if current_x>temp_rect[2]:
    temp_rect=(temp_rect[0],temp_rect[1],current_x,temp_rect[3])
  elif current_x<temp_rect[0]:
    temp_rect=(current_x,temp_rect[1],temp_rect[2],temp_rect[3])
  if current_y>temp_rect[3]:
    temp_rect=(temp_rect[0],temp_rect[1],temp_rect[2],current_y)
  elif current_y<temp_rect[1]:
    temp_rect=(temp_rect[0],current_y,temp_rect[2],temp_rect[3])
  return temp_rect


def move_cur_dir(current_pos, current_dir_id):
  if current_dir_id == 0: # up
    current_pos=(current_pos[0], current_pos[1]+1)
  elif current_dir_id == 1: # right
    current_pos=(current_pos[0]+1, current_pos[1])
  elif current_dir_id == 2: # down
    current_pos=(current_pos[0], current_pos[1]-1)
  elif current_dir_id == 3: # left
    current_pos=(current_pos[0]-1, current_pos[1])
  return current_pos