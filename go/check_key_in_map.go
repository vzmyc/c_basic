package main

func main() {
    tickers := map[string]string{
        "GOOG": "Google Inc",
        "MSFT": "Microsoft",
        "FB":   "FaceBook",
        "AMZN": "Amazon",
    }

    if _, exists := tickers["MSFT"]; exists {
        println("MSFT ticker")
    } else {
        println("No MSFT ticker")
    }
}
