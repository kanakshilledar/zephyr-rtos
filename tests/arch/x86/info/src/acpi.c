/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (c) 2019 Intel Corp.
 */

#include <zephyr/kernel.h>
<<<<<<< HEAD
#include <zephyr/arch/x86/acpi.h>

static void vtd_dev_scope_info(struct acpi_dmar_dev_scope *dev_scope)
{
	struct acpi_dmar_dev_path *path;
	uint16_t id;
	int n_path;

	printk("\t\t\t. Type: ");

	switch (dev_scope->type) {
	case ACPI_DRHD_DEV_SCOPE_PCI_EPD:
		printk("PCI Endpoint");
		break;
	case ACPI_DRHD_DEV_SCOPE_PCI_SUB_H:
		printk("PCI Sub-hierarchy");
		break;
	case ACPI_DRHD_DEV_SCOPE_IOAPIC:
		printk("IOAPIC");
		break;
	case ACPI_DRHD_DEV_SCOPE_MSI_CAP_HPET:
		printk("MSI Capable HPET");
		break;
	case ACPI_DRHD_DEV_SCOPE_NAMESPACE_DEV:
=======
#include <zephyr/acpi/acpi.h>

static const uint32_t dmar_scope[] = {ACPI_DMAR_SCOPE_TYPE_ENDPOINT, ACPI_DMAR_SCOPE_TYPE_BRIDGE,
				      ACPI_DMAR_SCOPE_TYPE_IOAPIC, ACPI_DMAR_SCOPE_TYPE_HPET,
				      ACPI_DMAR_SCOPE_TYPE_NAMESPACE};

static void vtd_dev_scope_info(int type, struct acpi_dmar_device_scope *dev_scope,
			       union acpi_dmar_id *dmar_id, int num_inst)
{
	int i = 0;

	printk("\t\t\t. Type: ");

	switch (type) {
	case ACPI_DMAR_SCOPE_TYPE_ENDPOINT:
		printk("PCI Endpoint");
		break;
	case ACPI_DMAR_SCOPE_TYPE_BRIDGE:
		printk("PCI Sub-hierarchy");
		break;
	case ACPI_DMAR_SCOPE_TYPE_IOAPIC:

		break;
	case ACPI_DMAR_SCOPE_TYPE_HPET:
		printk("MSI Capable HPET");
		break;
	case ACPI_DMAR_SCOPE_TYPE_NAMESPACE:
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		printk("ACPI name-space enumerated");
		break;
	default:
		printk("unknown\n");
		return;
	}

<<<<<<< HEAD
	id = z_acpi_get_dev_id_from_dmar(dev_scope->type);
	if (id != USHRT_MAX) {
		printk(" ID 0x%x", id);
	}

	printk("\n");

	printk("\t\t\t. Enumeration ID %u\n", dev_scope->enumeration_id);
	printk("\t\t\t. PCI Bus %u\n", dev_scope->start_bus_num);

	path = z_acpi_get_dev_scope_paths(dev_scope, &n_path);
	for (; n_path > 0; n_path--) {
		printk("\t\t\t. Path D:%u F:%u\n",
		       path->device, path->function);
		path = (struct acpi_dmar_dev_path *)(POINTER_TO_UINT(path) +
						     ACPI_DMAR_DEV_PATH_SIZE);
=======
	printk("\n");

	printk("\t\t\t. Enumeration ID %u\n", dev_scope->EnumerationId);
	printk("\t\t\t. PCI Bus %u\n", dev_scope->Bus);

	for (; num_inst > 0; num_inst--, i++) {
		printk("Info: Bus: %d, dev:%d, fun:%d\n", dmar_id[i].bits.bus,
			dmar_id[i].bits.device, dmar_id[i].bits.function);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}

	printk("\n");
}

<<<<<<< HEAD
static void vtd_drhd_info(struct acpi_drhd *drhd)
{
	struct acpi_dmar_dev_scope *dev_scope;
	int n_ds, i;

	if (drhd->flags & ACPI_DRHD_FLAG_INCLUDE_PCI_ALL) {
=======
static void vtd_drhd_info(struct acpi_dmar_hardware_unit *drhd)
{
	struct acpi_dmar_device_scope dev_scope;
	union acpi_dmar_id dmar_id[4];
	int num_inst, i;

	if (drhd->Flags & ACPI_DRHD_FLAG_INCLUDE_PCI_ALL) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		printk("\t\t- Includes all PCI devices");
	} else {
		printk("\t\t- Includes only listed PCI devices");
	}

	printk(" under given Segment\n");

<<<<<<< HEAD
	printk("\t\t- Segment number %u\n", drhd->segment_num);
	printk("\t\t- Base Address 0x%llx\n", drhd->base_address);

	dev_scope = z_acpi_get_drhd_dev_scopes(drhd, &n_ds);
	if (dev_scope == NULL) {
		printk("\t\t- No device scopes\n");
		return;
	}

	printk("\t\t- Device Scopes:\n");
	for (i = 0; i < n_ds; i++) {
		vtd_dev_scope_info(dev_scope);
		dev_scope = (struct acpi_dmar_dev_scope *)(
			POINTER_TO_UINT(dev_scope) + dev_scope->length);
=======
	printk("\t\t- Segment number %u\n", drhd->Segment);
	printk("\t\t- Base Address 0x%llx\n", drhd->Address);

	printk("\t\t- Device Scopes:\n");
	for (i = 0; i < 5; i++) {
		if (acpi_drhd_get(dmar_scope[i], &dev_scope, dmar_id, &num_inst, 4u)) {
			printk(" No DRHD entry found for scope type:%d\n", dmar_scope[i]);
			continue;
		}

		printk("Found DRHD entry: %d\n", i);

		vtd_dev_scope_info(dmar_scope[i], &dev_scope, dmar_id, num_inst);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}

	printk("\n");
}

static void vtd_info(void)
{
<<<<<<< HEAD
	struct acpi_dmar *dmar;

	dmar = z_acpi_find_dmar();
=======
	struct acpi_table_dmar *dmar;
	struct acpi_dmar_hardware_unit *drhd;

	dmar = acpi_table_get("DMAR", 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	if (dmar == NULL) {
		printk("\tIntel VT-D not supported or exposed\n");
		return;
	}

	printk("\tIntel VT-D Supported:\n");

	printk("\t-> X2APIC ");
<<<<<<< HEAD
	if (dmar->flags & ACPI_DMAR_FLAG_X2APIC_OPT_OUT) {
=======
	if (dmar->Flags & ACPI_DMAR_FLAG_X2APIC_OPT_OUT) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		printk("should be opted out\n");
	} else {
		printk("does not need to be opted out\n");
	}

<<<<<<< HEAD
	if (dmar->flags & ACPI_DMAR_FLAG_INTR_REMAP) {
		struct acpi_drhd *drhd;
		int hw_n, i;

		printk("\t-> Interrupt remapping supported\n");

		drhd = z_acpi_find_drhds(&hw_n);
		printk("\t-> %u remapping hardware found:\n", hw_n);

		for (i = 0; i < hw_n; i++) {
			printk("\t\tDRHD %u:\n", i);
			vtd_drhd_info(drhd);
			drhd = (struct acpi_drhd *)(POINTER_TO_UINT(drhd) +
						    drhd->entry.length);
		}
=======
	if (dmar->Flags & ACPI_DMAR_FLAG_INTR_REMAP) {

		printk("\t-> Interrupt remapping supported\n");

		if (acpi_dmar_entry_get(ACPI_DMAR_TYPE_HARDWARE_UNIT,
					(struct acpi_subtable_header **)&drhd)) {
			printk("error in retrieve DHRD!!\n");
			return;
		}
		vtd_drhd_info(drhd);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	} else {
		printk("\t-> Interrupt remapping not supported\n");
	}
}

void acpi(void)
{
<<<<<<< HEAD
	int nr_cpus;

	for (nr_cpus = 0; z_acpi_get_cpu(nr_cpus); ++nr_cpus) {
		/* count number of CPUs present */
=======
	int nr_cpus = 0, i, inst_cnt;
	struct acpi_madt_local_apic *lapic;

	if (acpi_madt_entry_get(ACPI_MADT_TYPE_LOCAL_APIC, (ACPI_SUBTABLE_HEADER **)&lapic,
				&inst_cnt)) {
		printk("error on get MAD table\n");
		return;
	}

	/* count number of CPUs present which are enabled*/
	for (i = 0; i < CONFIG_MP_MAX_NUM_CPUS; i++) {
		if (lapic[i].LapicFlags & 1u) {
			nr_cpus++;
		}
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}

	if (nr_cpus == 0) {
		printk("ACPI: no RSDT/MADT found\n\n");
	} else {
		printk("ACPI: %d CPUs found\n", nr_cpus);

<<<<<<< HEAD
		for (int i = 0; i < nr_cpus; ++i) {
			struct acpi_cpu *cpu = z_acpi_get_cpu(i);
			printk("\tCPU #%d: APIC ID 0x%02x\n", i, cpu->apic_id);
=======
		for (i = 0; i < CONFIG_MP_MAX_NUM_CPUS; ++i) {
			printk("\tCPU #%d: APIC ID 0x%02x\n", i, lapic[i].Id);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		}
	}

	printk("\n");

	vtd_info();

	printk("\n");
}
