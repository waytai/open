package main

import (
	"encoding/hex"
	"flag"
	"fmt"
	"github.com/brocaar/lorawan"
	MQTT "github.com/eclipse/paho.mqtt.golang"
	"log"
	"os"
	"strings"
)

func getphyframe(nskey []byte, askey []byte, addr []byte) string {
	var nwkSKey [16]byte
	var appSKey [16]byte
	var addr_len [4]byte

	for i, e := range nskey {
		nwkSKey[i] = e
	}

	for i, e := range askey {
		appSKey[i] = e
	}

	for i, e := range addr {
		addr_len[i] = e
	}

	fPort := uint8(120)

	phy := lorawan.PHYPayload{
		MHDR: lorawan.MHDR{
			MType: lorawan.ConfirmedDataUp,
			Major: lorawan.LoRaWANR1,
		},
		MACPayload: &lorawan.MACPayload{
			FHDR: lorawan.FHDR{
				DevAddr: addr_len,
				FCtrl: lorawan.FCtrl{
					ADR:       false,
					ADRACKReq: false,
					ACK:       false,
				},
				FCnt:  0,
				FOpts: []lorawan.MACCommand{}, // you can leave this out when there is no MAC command to send
			},
			FPort:      &fPort,
			FRMPayload: []lorawan.Payload{&lorawan.DataPayload{Bytes: []byte("12312")}},
		},
	}

	if err := phy.EncryptFRMPayload(appSKey); err != nil {
		panic(err)
	}

	if err := phy.SetMIC(nwkSKey); err != nil {
		panic(err)
	}

	str, err := phy.MarshalText()
	if err != nil {
		panic(err)
	}

	bytes, err := phy.MarshalBinary()
	if err != nil {
		panic(err)
	}

	phyJSON, err := phy.MarshalJSON()
	if err != nil {
		panic(err)
	}

	fmt.Println(string(str))
	fmt.Println(bytes)
	fmt.Println(string(phyJSON))
	return string(str)
}

func mqttpub(payload string) {
	topic := flag.String("topic", "gateway/b827ebfffe8759a6/rx", "The topic name to/from which to publish/subscribe")
	broker := flag.String("broker", "tcp://127.0.0.1:1883", "The broker URI. ex: tcp://10.10.1.1:1883")
	password := flag.String("password", "123456", "The password (optional)")
	user := flag.String("user", "loraserver", "The User (optional)")
	id := flag.String("id", "testgoid", "The ClientID (optional)")
	cleansess := flag.Bool("clean", false, "Set Clean Session (default false)")
	qos := flag.Int("qos", 0, "The Quality of Service 0,1,2 (default 0)")
	store := flag.String("store", ":memory:", "The Store Directory (default use memory store)")
	flag.Parse()

	opts := MQTT.NewClientOptions()
	opts.AddBroker(*broker)
	opts.SetClientID(*id)
	opts.SetUsername(*user)
	opts.SetPassword(*password)
	opts.SetCleanSession(*cleansess)
	if *store != ":memory:" {
		opts.SetStore(MQTT.NewFileStore(*store))
	}

	client := MQTT.NewClient(opts)
	if token := client.Connect(); token.Wait() && token.Error() != nil {
		panic(token.Error())
	}
	fmt.Println("Sample Publisher Started")

	//	payload := "test for liu\n"
	token := client.Publish(*topic, byte(*qos), false, payload)
	token.Wait()

	client.Disconnect(250)
	fmt.Println("Sample Publisher Disconnected")

}

func string_to_hexstring(src string) string {
	decoded, err := hex.DecodeString(src)
	if err != nil {
		log.Fatal(err)
	}

	return string(decoded)
}

func main() {
	if len(os.Args) != 4 {
		log.Fatalf("args len not equal 2")
	}

	nwkkey_str := string_to_hexstring(os.Args[1])
	appskey_str := string_to_hexstring(os.Args[2])
	addr_str := string_to_hexstring(os.Args[3])
	//nwkkey_str := "92bb47a797a3813188ecb1cb315a7b5a"
	//appskey_str := "1796a33bca9ae5f6f9c23ddd91c84b8e"
	//addr_str := "06d23d21"

	nskey := []byte(nwkkey_str)
	askey := []byte(appskey_str)
	addr := []byte(addr_str)
	phyfrm := getphyframe(nskey, askey, addr)
	fmt.Println(phyfrm)

	raw_payload := "{\"rxInfo\":{\"mac\":\"b827ebfffe8759a6\",\"time\":\"0001-01-01T00:00:00Z\",\"timestamp\":61979700,\"frequency\":471700000,\"channel\":3,\"rfChain\":1,\"crcStatus\":1,\"codeRate\":\"4/5\",\"rssi\":-69,\"loRaSNR\":8.5,\"size\":18,\"dataRate\":{\"modulation\":\"LORA\",\"spreadFactor\":12,\"bandwidth\":125}},\"phyPayload\":\"gOEj8QeAAQB7I+w5IbUiou8m\"}"
	payload := strings.Replace(raw_payload, "gOEj8QeAAQB7I+w5IbUiou8m", phyfrm, 1)
	mqttpub(payload)
}
