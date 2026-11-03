import streamlit as st
from testing_gem import search
ans = st.text_input("Enter your name")
text = search(ans)
st.text(text)