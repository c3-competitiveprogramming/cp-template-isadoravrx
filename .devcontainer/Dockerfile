FROM mcr.microsoft.com/devcontainers/base:jammy
RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install vim cmake vim-nox python3-dev gdb time
USER vscode
WORKDIR /home/vscode

######## VIM ########
RUN git clone https://github.com/VundleVim/Vundle.vim.git /home/vscode/.vim/bundle/Vundle.vim
RUN git config --global --add safe.directory /home/vscode/.vim/bundle/Vundle.vim
COPY .devcontainer/.vimrc /home/vscode/.vimrc
RUN vim +PluginInstall +qall
RUN python3 /home/vscode/.vim/bundle/YouCompleteMe/install.py --clangd-completer

######## JAVA ########
# RUN curl -s "https://get.sdkman.io" -o /home/vscode/.sdkman  | bash
# RUN source "/home/vscode/.sdkman/bin/sdkman-init.sh"
# RUN sdk install gradle
# RUN sdk install java 19.0.2-open
