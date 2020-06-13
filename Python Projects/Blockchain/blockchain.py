# Initializing our blockchain list
blockchain = []

def get_last_block_value():
    """Returns the last value of the current blockchain"""
    return blockchain[-1]


def add_value(transaction_amount, last_trans):
    """ Appends a new value as well as the last blockchain value to the blockchain
    
    Arguments: 
        :transaction_amount: The amount that should be added
        :last_trans: The last blockchain transaction (default [1]).
    """
    blockchain.append([last_trans, transaction_amount])

def get_user_input():
    return float(input("Your transaction amount please : "))

add_value(tx_amount, 1)
add_value(last_trans=get_last_block_value(), transaction_amount = 0.9)
add_value(3.2, get_last_block_value())

print(blockchain)