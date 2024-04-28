def hacker(log):
    log.reverse()
    credential_dict = {}
    #log = [("****1234********","maria@mail.pt"),("0000************","ze@gmail.com"),("****1111****3333","ze@gmail.com")]
    for x in log:
        if x[1] not in credential_dict:
            credential_dict[x[1]]=x[0]
        else:
            credential_dict[x[1]] = update_password(credential_dict , x)
    
    credential_list = list(credential_dict.items())
    credential_list = [(x[1],x[0]) for x in credential_list]
    credential_list.sort(key= lambda x: x[1])
    credential_list.sort(key= lambda x:num_of_unknown(x[0]))
    return credential_list

def num_of_unknown(word):
    counter = 0
    for x in word:
        if x == "*":
            counter+=1
    return counter

def update_password(credential_dict , x):
    new_password = x[0]
    email = x[1]
    password_to_update = credential_dict[email]
    for i,letra in enumerate(password_to_update):
        if new_password[i] != "*":
            password_to_update = password_to_update[:i]+new_password[i]+password_to_update[i+1:]
    return password_to_update