#
# ~/.bash_profile
#

[[ -f ~/.bashrc ]] && . ~/.bashrc

export DOTNET_ROOT=$HOME/.dotnet
export PATH=$PATH:$HOME/.dotnet:$HOME/.dotnet/tools
