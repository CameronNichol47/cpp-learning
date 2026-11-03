import time
from google import genai
from google.genai import types

client = genai.Client(
    http_options=types.HttpOptions(
        retry_options=types.HttpRetryOptions(attempts=1),
        timeout=30000
    )
)

start = time.perf_counter()
def search(text):
    try:
        response = client.models.generate_content(
            model="gemini-3.1-flash-lite",
            contents=text
        )

        return response.text

    except Exception as e:
        print("Error:", e)

print(f"Response time: {time.perf_counter() - start:.2f}s")