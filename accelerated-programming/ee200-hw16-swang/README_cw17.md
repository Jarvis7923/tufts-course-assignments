# Resources
You should fill in this section with the resources that you used to develop your code.  You don't need to include the teaching staff or the textbook, but you should list anyone you worked with, and any online or paper resources you used.

# Overview
Many applications which use priority queues have separate threads for reading and writing, and it's important that the priority queue doesn't get corrupted if two threads access it at once.

Your job is to update your PriorityQueue class to be thread-safe.  That is, it should always produce correct results, even if multiple threads a reading and writing to it at the same time.
You should try to maximize performance (i.e., don't lock more than you need to), but not at the expense of correctness!

# Submission
Your code should be pushed to Github, and then you should submit to Gradescope from there.  You will not be able to upload files directly.

# Testing
Testing multithreaded code is notoriously hard, because it is non-deterministic.  However, you can build confidence that your code is working by creating scenarios where bugs would likely occur if your code was incorrect.  You'll want to read and write many elements (not just a few, or even a few hundred), and you'll probably want to have many threads competing for access, not just two.

