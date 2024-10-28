#!/bin/bash

# Install norminette
pip install norminette

# Check the user base directory
python3 -m site --user-base

# Add the bin directory to PATH if not already added
if ! grep -q "/var/data/python/bin" ~/.bashrc; then
    echo 'export PATH="/var/data/python/bin:$PATH"' >> ~/.bashrc
    echo "Added /var/data/python/bin to PATH in .bashrc"
else
    echo "/var/data/python/bin is already in PATH"
fi

# Apply changes to the current shell session
source ~/.bashrc

# Verify that norminette is accessible
norminette --version
