# Answers to the questions from assignment 17

## a)
Memset was replaced by a for loop setting every byte to '0' manually.

## b)
SOL_SOCKET:
Specifies at which protocol level the options shall be applied, in this case the socket level.

SO_REUSEADDR:
When an address is validet in the bind() function this argument allows to reuse a local address (if supported by the protocol).
