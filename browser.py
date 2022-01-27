from hashlib import sha256
MAX_NONCE = 10000000
def SHA256(text):
    return sha256(text.encode("ascii")).hexdigest()
def mine(the_block_number, transactions, the_previous_hash, prefix_zeros):
    prefix_str = '0'*prefix_zeros
    for nonce in range(MAX_NONCE):
        text = str(the_block_number) + transactions + the_previous_hash + str(nonce)
        the_new_hash = SHA256(text)
        if the_new_hash.startswith(prefix_str):
            print("successfully mined bitcoins with nonce value:",nonce)
            return the_new_hash
    raise BaseException("couldn't find correct hash after trying",MAX_NONCE,"times")
if __name__ == '__main__':
    transaction = '''no1->no2->20,no3->no4->45,no3->no2->67'''
    difficulty = int(input("enter the difficulty:"))
    block_number = int(input("enter the height:"))
    previous_hash = input("enter the previous hash:")
    import time
    start = time.time()
    print("started mining")
    new_hash = mine(block_number, transaction, previous_hash, difficulty)
    total_time = str((time.time()-start))
    print("mining ended")
    print("mining took:",total_time,"seconds")
    print("new hash:",new_hash)