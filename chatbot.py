def set_data(data):
    with open("data.txt", "r") as file:
        for line in file:
            parts = line.strip().split()
            if len(parts) == 2:
                key, value = parts
                value = value.replace('_', ' ')
                key = key.lower()
                data[key] = value

if __name__ == "__main__":
    data = {}
    set_data(data)

    print("\nPICT Chatboat: How can I help you today!")

    while True:
        input_str = input("\nYou: ").lower().replace(' ', '')

        found = False
        for key, value in data.items():
            if key in input_str:
                print("\nChatBot:", value)
                found = True
                break

        if not found:
            print("ChatBot: Data is not present in the data set! Please provide the answer. Enter the data in key value pairs.")

            key = input("Key: ").strip().lower().replace(' ', '')
            value = input("Value: ").strip().replace(' ', '_')

            data[key] = value

            with open("data.txt", "a") as file:
                file.write(f"\n{key} {value}")
                
            print("Data remembered!")
