# Super_Market_Billing_Sysyem
Super Market billing and administrative system using tree data structures.
Here we have tried to build a billing software.
We have added two sections in the software.One is the admin part and second one is the customer/client part.
Admin is secured by a password.Only admin account has the access to the store inventory.Only he can add or delete elements in the store inventory.
We have also added expired items section in the admin part where we can have a look at the expired items with respect to the current date.
In Customer part we have implemented the billing calculations where billing is done through the barcodes of the producrs.
# Technical Stuff
We selected Binary tree as it makes retrieval of elements faster.We are storing all elements in file.Whenever the code is executed the elements in the file are stored into the tree.
Elements retrieval takes barcodes as the main key to search the elements in the time of billing.
Whenever an element is added or deleted from store inventory the elemen dynamically gets deleted in both the files and the tree data structure.
