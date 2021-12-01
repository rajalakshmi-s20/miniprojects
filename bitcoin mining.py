from hashlib import sha256
MAX_NONCE=10000000
def SHA256(text):
    return sha256(text.encode("ascii")).hexdigest()
def mine (block_number, transactions, previous_hash, prefix_zeros):
    prefix_str='0'*prefix_zeros
    for nonce in range(MAX_NONCE):
        text=str(block_number)+transactions+previous_hash+str(nonce)
        new_hash=SHA256(text)
        if new_hash.startswith(prefix_str):
            print("successfully mined bitcoins with nonce value:",nonce)
            return new_hash
    raise BaseException ("couldn't find correct hash after trying",MAX_NONCE,"times")
if __name__=='__main__':
    transactions='''no1->no2->20,no3->no4->45,no3->no2->67'''
    difficulty = 4
    import time
    start=time.time()
    print("started mining")
    new_hash = mine(5, transactions,'fgjhkmzxcvbnbvcxcvbnbvcxcvbnbvvb', difficulty)
    total_time = str((time.time()-start))
    print("mining ended, it took:",total_time,"seconds")
    print(new_hash)
